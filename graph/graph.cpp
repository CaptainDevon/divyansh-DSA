#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph(int nodes);
    void addEdge(int u, int v);
    void dfs(int node);
    void bfs(int node);

private:
    int nodes;
    vector<vector<int>> adjList;
    vector<bool> visited;
    void dfsUtil(int node);
    void bfsUtil(int node);
};

Graph::Graph(int nodes) : nodes(nodes), adjList(nodes), visited(nodes, false) {}

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::dfsUtil(int node)
{
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfsUtil(neighbor);
        }
    }
}

void Graph::dfs(int node)
{

    fill(visited.begin(), visited.end(), false);
    dfsUtil(node);
}

void Graph::bfs(int startNode)
{
    fill(visited.begin(), visited.end(), false); // Reset the visited array
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    Graph gr(6);

    gr.addEdge(0, 1);
    gr.addEdge(0, 2);
    gr.addEdge(1, 3);
    gr.addEdge(1, 4);
    gr.addEdge(2, 4);
    gr.addEdge(3, 5);
    gr.addEdge(4, 5);

    gr.dfs(0);
    gr.bfs(0);

    return 0;
}
