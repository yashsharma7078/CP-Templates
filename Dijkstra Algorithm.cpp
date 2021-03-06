// Code for finding single source shortest path using dijkstra algorithm.
// Time Complexity - O(n.logn + m.logn) where n is the number of vertices and m is the number of edges in the graph.
// Used for directed/undirected graphs with non-negative edge weights.

int dist[LIM], parent[LIM];
vii adj[LIM];

void dijkstra(int s)
{
    for (int i = 0; i < LIM; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[s] = 0;
    set<pii> nodes;
    nodes.insert({0, s});

    while (!nodes.empty())
    {
        int v = nodes.begin()->second;
        nodes.erase(nodes.begin());

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (dist[v] + len < dist[to])
            {
                nodes.erase({dist[to], to});
                dist[to] = dist[v] + len;
                parent[to] = v;
                nodes.insert({dist[to], to});
            }
        }
    }
}
