#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {
        // The minimum number of zelda-operations required is ceil(log2(n))
        // This is because in each operation, we can at most halve the number of vertices.
        return ceil(log2(n));
    }
};


#endif