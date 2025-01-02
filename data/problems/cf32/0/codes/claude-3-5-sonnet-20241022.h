#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    
    pair<int, int> findFarthest(int start, int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int maxDist = 0;
        int farthestNode = start;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next : adj[curr]) {
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                    if (dist[next] > maxDist) {
                        maxDist = dist[next];
                        farthestNode = next;
                    }
                }
            }
        }
        
        return {farthestNode, maxDist};
    }
    
    int solve(int n, vector<pair<int, int>> &edges) {
        // Create adjacency list
        adj.resize(n + 1);
        for (auto &edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        
        // Find diameter of the tree
        pair<int, int> end1 = findFarthest(1, n);
        pair<int, int> end2 = findFarthest(end1.first, n);
        int diameter = end2.second;
        
        // Calculate minimum operations needed
        return (diameter + 1) / 2;
    }
};


#endif