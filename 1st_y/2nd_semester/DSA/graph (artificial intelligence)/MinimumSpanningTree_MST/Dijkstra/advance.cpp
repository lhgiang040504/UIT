#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &);

void Dijkstra(string a, string b, unordered_map<string, vector<pair<string, int>>> adjList) {
    unordered_map<string, bool> visited;
    unordered_map<string, string> parent;

    unordered_map<string, int> Open;
    Open.insert({a, 0});
    visited[a] = true;

    while (!Open.empty()) {
        // Get edge that has min weight
        auto minWeight = min_element(Open.begin(), Open.end(), 
            [](const pair<string, int>& a, const pair<string, int>& b) {
                               return a.second < b.second;
            });
    
        if (minWeight->first == b)
            break;
    
        string from = minWeight->first;
        Open.erase(minWeight->first);
        for (auto& i : adjList[from]) {
            
            // note: one important condition that replace the one by their better
            if (visited[i.first]) {
                if (i.second >= Open[i.first])
                    continue;
                Open[i.first] = i.second;
            }
            else {
                Open.insert({i.first, i.second});
                visited[i.first] = true;
            }
            
            parent[i.first] = from; 
        }
    }
    
    if (Open.empty()) {
        cout << "no_path" << endl;
        return;
    }

    int cost = 0;
    string res = "";
    for(string at = b; at != a; at = parent[at]) {
        
        for (const auto& pair : adjList[parent[at]]) {
            if (pair.first == at) {
                cost += pair.second;
                break;
            }
        }

        res = at + res;
        res = " " + res;
    }
    res = a + res + " ";
    cout << res << cost << "\n";
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
    unordered_map<string, vector<pair<string, int>>> adjList;

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_weight_temp;
        getline(cin, t_from_to_weight_temp);

        vector<string> t_from_to_weight = split(t_from_to_weight_temp);
        string from = t_from_to_weight[0];
        string to = t_from_to_weight[1];
        int weight = stoi(t_from_to_weight[2]);

        adjList[from].push_back(make_pair(to, weight));
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
        Dijkstra((*it).first, (*it).second, adjList);
        
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