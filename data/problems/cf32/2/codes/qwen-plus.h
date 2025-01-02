#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {
        // A tree with n vertices will have n-1 edges.
        // To compress the tree into a single vertex, we need to perform
        // n-1 operations because each operation reduces the number of vertices by 1.
        return n - 1;
    }
};


#endif