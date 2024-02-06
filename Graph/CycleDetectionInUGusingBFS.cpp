//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int src, vector<int> &visited, vector<int> adj[])
    {
        unordered_map<int, int> parent;

        parent[src] = -1;
        visited[src] = 1;
        queue<int> q;

        q.push(src);

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adj[frontNode])
            {
                if (visited[neighbour] == 1 && neighbour != parent[frontNode])
                {
                    return true;
                }
                else if (visited[neighbour] == 0)
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        bool ans;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (isCyclic(i, visited, adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends