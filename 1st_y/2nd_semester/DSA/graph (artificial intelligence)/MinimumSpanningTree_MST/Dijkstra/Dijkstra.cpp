#include <bits/stdc++.h>
using namespace std;

void Dijkstra(char a, char b, unordered_map<char, vector<pair<char, int>>> adjList) {
    unordered_map<char, bool> visited;
    unordered_map<char, char> parent;

    unordered_map<char, int> Open;
    Open[a] = 0;
    visited[a] = true;

    while (!Open.empty()) {
        // Get edge that has min weight
        auto minWeight = min_element(Open.begin(), Open.end(), 
            [](const pair<char, int>& a, const pair<char, int>& b) {
                               return a.second < b.second;
            });
    
        if (minWeight->first == b)
            break;
    
        char from = minWeight->first;
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
    for(char at = b; at != a; at = parent[at]) {
        
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
    cout << res << cost <<"\n";
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    char Node[numNodes];
    for (int i = 0; i < numNodes; i++) {
        cin >> Node[i];
    }

    // Create an adjustList
    unordered_map<char, vector<pair<char, int>>> adjList;

    for (int i = 0; i < numEdges; i++) {
        char from, to;
        int weight;
        cin >> from >> to >> weight;

        adjList[from].push_back(make_pair(to, weight));
    }
    
    int numPair;
    cin >> numPair;
    vector<pair<char, char>> Pair;
    cin.ignore();
    for (int i = 0; i < numPair; i++) {
        char from, to;
        cin >> from >> to;
       
        Pair.push_back(make_pair(from, to));
    }
    
    for (auto it = Pair.begin(); it != Pair.end(); it++) 
        Dijkstra((*it).first, (*it).second, adjList);
        
    return 0;
}
