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
            queue<int> q;
            q.push(start);
            visited[start] = true;
            bool canReturn = false;
            
            // BFS to find if we can return to start
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                // Check all neighbors
                for (int next : adj[curr]) {
                    if (next == start && curr != start) {
                        canReturn = true;
                        break;
                    }
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                
                if (canReturn) break;
            }
            
            if (canReturn) returnable++;
        }
        
        return returnable;
    }
};


#endif