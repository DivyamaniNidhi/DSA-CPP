//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        vector<int> visited(V, 0);
        visited[c] = 1;

        queue<int> q;
        for (auto v : adj[c])
        {
            if (v != d)
            {
                q.push(v);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == d)
            {
                return 0;
            }

            for (auto nbr : adj[u])
            {
                if (visited[nbr] == 0)
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        return !visited[d];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends