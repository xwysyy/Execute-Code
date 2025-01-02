#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {
        // The minimum number of zelda-operations required to reduce the tree to a single vertex
        // is always n - 1, where n is the number of vertices in the tree.
        return n - 1;
    }
};


#endif