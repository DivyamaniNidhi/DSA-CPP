//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int src, int parent, vector<int> &visited, vector<int> adj[])
    {
        visited[src] = 1;

        for (auto neighbour : adj[src])
        {
            if (visited[neighbour] == 0)
            {
                bool cycleDetected = isCyclic(neighbour, src, visited, adj);
                if (cycleDetected)
                    return true;
            }
            else if (neighbour != parent)
            {
                return true;
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
                if (isCyclic(i, -1, visited, adj))
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