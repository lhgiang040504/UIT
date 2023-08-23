#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &);

void DFS(string a, string b, unordered_map<string, vector<string>> adjList) {
    /*
    if (a == b) {
        std::cout << a << " ";
        DFS(edges, edges[a].back(), b);
        return;
    }
    */
    
    queue<string> open;
    unordered_map<string, bool> visited;
    unordered_map<string, string> parent;
    
    open.push(a);
    visited[a] = true;
    while(!open.empty()) {
        string node = open.front();
        open.pop();
        
        for(auto& i : adjList[node]) {
            if(!visited[i]) {
                parent[i] = node;
                open.push(i);
                visited[i] = true;
            }
            if (i == b) break;
        }
    }
    // b not in parent
    if(parent.find(b) == parent.end()) {
        cout << "no_path\n";
        return;
    }

    string res = "";
    for(string at = b; at != a; at = parent[at]) {
        if (find(adjList[a].begin(), adjList[a].end(), at) != adjList[a].end() && find(adjList[a].begin(), adjList[a].end(), parent[at]) != adjList[a].end()) {
            res = at + res;
            res = " " + res;
            break;
        }
        res = at + res;
        res = " " + res;
    }
    res = a + res;
    cout << res << "\n";
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

    // Create an adjustList
    unordered_map<string, vector<string>> adjList;

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(t_from_to_temp);
        adjList[t_from_to[0]].push_back(t_from_to[1]);
    }
    
    int numPair;
    cin >> numPair;
    vector<pair<string, string>> Pair;
    cin.ignore();
    for (int i = 0; i < numPair; i++) {
        string t_from_to_temp;
        
        getline(cin, t_from_to_temp);
        
        vector<string> input = split(t_from_to_temp);

        Pair.push_back(make_pair(input[0], input[1]));
    }
    
    for (auto it = Pair.begin(); it != Pair.end(); it++) 
        /*stack<int> Path = */ DFS((*it).first, (*it).second, adjList);
        
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