#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

int main()

/*
Output:
Edge: (1, 3), Weight: 1
Edge: (2, 3), Weight: 2
Edge: (1, 2), Weight: 3
*/
{
    std::vector<Edge> edges = {
        {1, 2, 3},
        {1, 3, 1},
        {2, 3, 2}};

    std::sort(edges.begin(), edges.end());

    for (const Edge &edge : edges)
    {
        std::cout << "Edge: (" << edge.u << ", " << edge.v << "), Weight: " << edge.weight << std::endl;
    }

    return 0;
}
