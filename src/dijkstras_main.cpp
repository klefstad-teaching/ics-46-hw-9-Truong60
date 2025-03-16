#include "dijkstras.h"

using namespace std;

void test_dijkstras()
{
    Graph graph;

    file_to_graph("large.txt", graph);

    vector<int> prev(graph.size());
    vector<int> dist = dijkstra_shortest_path(graph, 0, prev);
    vector<int> path = extract_shortest_path(dist, prev, 3);
    int total = dist[3];
    print_path(path, total);
}

int main()
{
    test_dijkstras();
}