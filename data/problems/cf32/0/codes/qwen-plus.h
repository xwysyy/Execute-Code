#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {   
        // A tree with n vertices will require n-1 edges to form.
        // To compress the tree into one vertex, we need to perform
        // zelda-operations that will reduce the number of vertices by 1 each time.
        // Since each operation can reduce the number of vertices by at least 1,
        // we need exactly n-1 operations to reduce the tree from n vertices to 1 vertex.
        return n - 1;
    }
};


#endif