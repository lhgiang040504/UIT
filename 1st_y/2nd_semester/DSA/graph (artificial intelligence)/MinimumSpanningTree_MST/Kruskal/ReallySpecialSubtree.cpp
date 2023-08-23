#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

struct Edge {
    int from;
    int to;
    int weight;
};

int findParent(vector<int>& parent, int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

void Union(vector<int>& parent, int node1, int node2) {
    int parent1 = findParent(parent, node1);
    int parent2 = findParent(parent, node2);
    parent[parent1] = parent2;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int g_edges = g_from.size();
    vector<Edge> edges(g_edges);
    
    // manage edges
    for (int i = 0; i < g_edges; i++) {
        edges[i].from = g_from[i];
        edges[i].to = g_to[i];
        edges[i].weight = g_weight[i];
    }
    
    // sort by increaseed weight condition
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    
    // do not scale the input
    vector<int> parent(g_nodes + 1);
    for (int i = 1; i <= g_nodes; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    int edgeCount = 0;

    for (const Edge& edge : edges) {
        int from = edge.from;
        int to = edge.to;
        int weight = edge.weight;

        // else discard 
        if (findParent(parent, from) != findParent(parent, to)) {
            Union(parent, from, to);
            mstWeight += weight;
            edgeCount++;
        }
    }

    if (edgeCount == g_nodes - 1) {
        return mstWeight;
    } else {
        return -1;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int result = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << result;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
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
