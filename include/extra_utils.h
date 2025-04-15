// graph_utils.h
#pragma once

#ifndef EXTRA_UTILS_H
#define EXTRA_UTILS_H

#include <vector>
#include <tuple>
#include <string>

using namespace std;

using Edge = tuple<int, int, int>;

bool readGraphFromFile(const string &filename, int &V, int &E, vector<Edge> &edges, int &source);

#endif
