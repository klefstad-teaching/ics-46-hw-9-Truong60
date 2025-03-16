#include "dijkstras.h"
#include <algorithm>


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int num_vert = G.size();
    vector<int> distances(num_vert, INF);
    vector<bool> visited(num_vert, false);
    distances[source] = 0;
    previous[source] = UNDEFINED;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({source, 0});
    while ( !minHeap.empty()){
        int u = minHeap.top().first;
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge edge: G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> store;
    for (int curr = destination; curr != -1; curr = previous[destination]){
        store.push_back(curr);
    }

    return store;
}