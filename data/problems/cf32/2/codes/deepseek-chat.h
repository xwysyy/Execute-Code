#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {
        if (n == 1) return 0;
        
        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        
        // Find all leaf nodes
        vector<int> leaves;
        for (auto &node : adj) {
            if (node.second.size() == 1) {
                leaves.push_back(node.first);
            }
        }
        
        // The minimum number of operations is the ceiling of (number of leaves / 2)
        return (leaves.size() + 1) / 2;
    }
};


#endif