vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, vector<int>> adjList;

    // create adjList
    for (auto it : edges)
    {
        adjList[it.first].push_back(it.second);
        adjList[it.second].push_back(it.first);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    parent[s] = -1;
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto nbr : adjList[front])
        {
            if (visited[nbr] == false)
            {
                parent[nbr] = front;
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
