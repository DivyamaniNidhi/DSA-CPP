//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector)
// edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a
// distance of edge[i][2] for all i.
// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to
// reach any vertex, then return -1 for that vertex.

class Solution
{
public:
    void dfs(int node, stack<int> &s, vector<int> &visited, unordered_map<int, vector<pair<int, int>>> &adjList)
    {
        visited[node] = 1;
        for (auto it : adjList[node])
        {
            if (!visited[it.first])
            {
                dfs(it.first, s, visited, adjList);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<pair<int, int>>> adjList;

        for (auto i : edges)
        {
            int u = i[0];
            pair<int, int> p = make_pair(i[1], i[2]);
            adjList[u].push_back({p});
        }

        vector<int> visited(N, 0);
        stack<int> s;

        // topo sort
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                dfs(i, s, visited, adjList);
            }
        }

        vector<int> distance(N, INT_MAX);

        int src = 0;
        distance[src] = 0;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (distance[top] != INT_MAX)
            {
                for (auto nbr : adjList[top])
                {
                    distance[nbr.first] = min(distance[nbr.first], distance[top] + nbr.second);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends