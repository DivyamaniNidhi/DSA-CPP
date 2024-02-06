void createAdjList(unordered_map<int, list<int>> &adjList, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    // recursive call for every connected node
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(adjList, visited, i, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    createAdjList(adjList, edges);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(adjList, visited, i, component);
            ans.push_back(component);
        }
    }

    return ans;
}