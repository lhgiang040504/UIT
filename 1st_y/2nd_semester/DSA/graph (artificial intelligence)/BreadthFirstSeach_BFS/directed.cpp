#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &);

stack<int> BFS(int start, int end, int n, vector<vector<int>> adjustList) {
    // Track of node visited
    vector<bool> visited(n, false);

    // Track of parent of each node
    vector<int> parent(n);

    queue<int> open;
    open.push(start);
    visited[start] = true;
    parent[start] = -1;

    // To complete the parent vector by BFS travel
    while (!open.empty()) {
        int node = open.front();
        if (node == end)
            break;
        open.pop(); 
        for (auto& nodes : adjustList[node])
            if (!visited[nodes]) {
                open.push(nodes);
                visited[nodes] = true;
                parent[nodes] = node;
            }
    }

    // Get the path from parent vector by travel from the end to start
    stack<int> path;
    if (!open.empty()) {
        path.push(end);
        int parentNode = parent[end];
        
        while (parentNode != start) {
            path.push(parentNode);
            parentNode = parent[parentNode];
        }

        path.push(start);
    }
    // Finally get the path
    return path;
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
    for (int i = 0; i < list_Nodes.size(); ++i)
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

    vector<stack<int>> Path(numPair);
    for (int i = 0; i < numPair; i++) {
        string t_from_to_temp;
        cin.ignore();
        getline(cin, t_from_to_temp);
        
        vector<string> t_from_to = split(t_from_to_temp);

        Path[i] = BFS(encodedMap[t_from_to[0]], encodedMap[t_from_to[1]], t_nodes, adjList);
    }

    for (int i = 0; i < numPair; i++) {
        if (Path[i].empty())
            cout << "no_path" << "\n";
        else {
            while (!Path[i].empty()) {
                cout << list_Nodes[Path[i].top()] << " ";
                Path[i].pop();
            }
            cout << endl;
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