#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    
    // Function to find the farthest node and its distance using DFS
    pair<int, int> dfs(int u, int parent, int depth) {
        pair<int, int> ret = {depth, u};
        for (int v : adj[u]) {
            if (v != parent) {
                ret = max(ret, dfs(v, u, depth + 1));
            }
        }
        return ret;
    }
    
    int solve(int n, vector<pair<int, int>> &edges) {
        // If tree has only one vertex, no operations needed
        if (n == 1) return 0;
        
        // Build adjacency list
        adj.resize(n + 1);
        for (auto &edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        
        // Find diameter of the tree
        // First DFS from any node (here, node 1) to find one end of diameter
        pair<int, int> end1 = dfs(1, 0, 0);
        // Second DFS from the found end to find actual diameter
        pair<int, int> end2 = dfs(end1.second, 0, 0);
        
        // Calculate minimum operations needed
        int diameter = end2.first;
        return (diameter + 1) / 2;
    }
};


#endif