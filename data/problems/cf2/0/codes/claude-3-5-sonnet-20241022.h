#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        vector<vector<int>> adj(n);
        // Build adjacency list based on conveyor belt directions
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if (s[i] == '>' || s[i] == '-') {
                adj[i].push_back(next);
            }
            if (s[i] == '<' || s[i] == '-') {
                adj[next].push_back(i);
            }
        }
        
        int returnable = 0;
        // Check each room
        for (int start = 0; start < n; start++) {
            vector<bool> visited(n, false);
            bool canReturn = false;
            
            // DFS from current room
            function<void(int)> dfs = [&](int curr) {
                visited[curr] = true;
                for (int next : adj[curr]) {
                    if (next == start && curr != start) {
                        canReturn = true;
                    }
                    if (!visited[next]) {
                        dfs(next);
                    }
                }
            };
            
            dfs(start);
            if (canReturn) returnable++;
        }
        
        return returnable;
    }
};


#endif