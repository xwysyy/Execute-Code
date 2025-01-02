#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {
        // Since the tree can be formed optimally in ceil(n/2) steps
        // Take ceiling of half of the nodes
        return (n + 1) / 2;
    }
};


#endif