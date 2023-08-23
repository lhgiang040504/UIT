#include <bits/stdc++.h>
using namespace std;
// adjList, start, end
void dfs(unordered_map<char, vector<char>> edges, char a, char b)
{
    if (a == b)
    {
        std::cout << a << " ";
        dfs(edges, edges[a].back(), b);
        return;
    }
    stack<char> NodeStack;
    unordered_map<char, bool> visited;
    unordered_map<char, char> prev;
    
    NodeStack.push(a);
    while(!NodeStack.empty())
    {
        char node = NodeStack.top();
        NodeStack.pop();
        if(!visited[node])
        {
            visited[node] = true;
            for(auto i : edges[node])
            {
                if(!visited[i])
                {
                    prev[i] = node;
                    NodeStack.push(i);
                }
                if (i == b) {goto Label;}
            }
        }
    }
    Label:
    if(prev.find(b) == prev.end())
    {
        cout << "no_path\n";
        return;
    }

    string res = "";
    for(char at = b; at != a; at = prev[at]) 
    {
        if (find(edges[a].begin(), edges[a].end(), at) != edges[a].end() && find(edges[a].begin(), edges[a].end(), prev[at]) != edges[a].end()) 
        {
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

int main()
{
    int n, e;
    cin >> n >> e;
    char node[n];
    for (int i = 0; i < n; i++)
    {
        cin >> node[i];
    }
    unordered_map<char, vector<char>> edges;
    for (int i = 0; i < e; i++)
    {
        char a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    int m;
    cin >> m;
    vector<pair<char, char>> quest;
    for(int i = 0; i < m; i++)
    {
        char a, b;
        cin >> a >> b;
        quest.push_back(make_pair(a, b));
    }
    
    for(auto it = quest.begin(); it != quest.end(); it++)
    {
        dfs(edges, (*it).first, (*it).second);
    }
}