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
    
    // Function to find the diameter of the tree
    int getDiameter() {
        // First DFS to find one end of diameter
        pair<int, int> end1 = dfs(0, -1, 0);
        // Second DFS from the found end to get the diameter
        pair<int, int> end2 = dfs(end1.second, -1, 0);
        return end2.first;
    }
    
    int solve(int n, vector<pair<int, int>> &edges) {
        // Create adjacency list representation
        adj.resize(n);
        for (auto &edge : edges) {
            int u = edge.first - 1;  // Convert to 0-based indexing
            int v = edge.second - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Each zelda-operation reduces the diameter by at least 2
        // (except possibly the last operation)
        int diameter = getDiameter();
        return (diameter + 1) / 2;
    }
};


#endif