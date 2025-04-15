#include "extra_utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
using namespace std;

using Edge = tuple<int, int, int>;

bool readGraphFromFile(const string &filename, int &V, int &E, vector<Edge> &edges, int &source)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    infile >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        infile >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    infile >> source;

    infile.close();
    return true;
}