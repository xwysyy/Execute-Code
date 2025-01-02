#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {   
        if (n == 1) return "NO";
        for (int k = 2; k <= 1000; ++k) {
            int total_nodes = 1 + k;
            int current_layer_nodes = k;
            while (total_nodes < n) {
                current_layer_nodes *= k;
                total_nodes += current_layer_nodes;
            }
            if (total_nodes == n) return "YES";
        }
        return "NO";
    }
};

#endif