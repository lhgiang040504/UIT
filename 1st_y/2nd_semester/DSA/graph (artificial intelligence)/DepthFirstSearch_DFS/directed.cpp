#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<string> split(const string &);

stack<int> DFS(int start, int end, int n, vector<vector<int>> adjustList) {
    // Track of node visited
    vector<bool> visited(n, false);
    // Track of parent of each node
    vector<int> parent(n);
    stack<int> open;
  
    open.push(start);
    visited[start] = true;

    int node;
    // To complete the parent vector by DFS travel
    while (!open.empty()) {
        node = open.top();
        
        if (node == end) {
            break;
        }
           
        open.pop(); 
        
        if (!(adjustList[node].empty())) 
            for (auto& nodes : adjustList[node])
                if (!visited[nodes]) {
                    open.push(nodes);
                    visited[nodes] = true;
                    parent[nodes] = node;
                }

    }

    
    if (open.empty()) {
        // No path exists, return an empty stack or a special value
        stack<int> emptyStack;
        return emptyStack;
        // Alternatively, you can return a special value like -1 or INT_MAX
    }
    else {
        stack<int> path;

        path.push(end);
        int parentNode = parent[end];

        while (parentNode != start) {
            path.push(parentNode);
            parentNode = parent[parentNode];
        }

        path.push(start);
        // Finally get the path
        return path;
    } 
}

int main() {
    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    // Address the format inut
    vector<string> t_nodes_edges = split(t_nodes_edges_temp);
    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    string listNode;
    getline(cin, listNode);
    vector<string> list_Nodes = split(listNode);

    unordered_map<string, int> encodedMap;
    // Encoding the vector
    for (int i = 0; i < list_Nodes.size(); i++)
        encodedMap[list_Nodes[i]] = i;
    
    // Create an adjustList
    vector<vector<int>> adjList(t_nodes);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(t_from_to_temp);
        adjList[encodedMap[t_from_to[0]]].push_back(encodedMap[t_from_to[1]]);
    }
    
    int numPair;
    cin >> numPair;
    vector<vector<string>> Pair(numPair);
    for (auto& pairs : Pair) {
        string t_from_to_temp;
        cin.ignore();
        getline(cin, t_from_to_temp);
        
        pairs = split(t_from_to_temp);
    }
    
    for (int i = 0; i < numPair; i++) {
        stack<int> Path = DFS(encodedMap[Pair[i][0]], encodedMap[Pair[i][1]], t_nodes, adjList);
        
        if (!Path.empty()) {
            while (!Path.empty()) {
                cout << list_Nodes[Path.top()] << " ";
                Path.pop();
            }
            cout << endl;
        }
        else {
            cout << "no_path" << "\n";
        }
    }
    return 0;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}