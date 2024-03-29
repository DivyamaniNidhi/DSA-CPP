//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, INT_MAX);
        set<pair<int, int>> st;
        st.insert(make_pair(0, S));
        distance[S] = 0;

        for (int i = 0; i < V; i++)
        {
            pair<int, int> top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;
            st.erase(st.begin());

            for (auto nbr : adj[node])
            {
                if (nodeDistance + nbr[1] < distance[nbr[0]])
                {
                    auto record = st.find(make_pair(distance[nbr[0]], nbr[0]));
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    distance[nbr[0]] = nodeDistance + nbr[1];
                    st.insert(make_pair(distance[nbr[0]], nbr[0]));
                }
            }
        }
        return distance;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends