#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x];
    }

    void union_sets(int x, int y, vector<int>& parent, vector<int>& rank) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px != py) {
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }

    string solve(int &n, string &s) {
        vector<int> parent(n), rank(n, 0);
        
        // Initialize union-find structure
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // First pass: process all equalities (E)
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'E') {
                union_sets(i, (i + 1) % n, parent, rank);
            }
        }
        
        // Second pass: process all non-equalities (N)
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N') {
                int pi = find(i, parent);
                int pnext = find((i + 1) % n, parent);
                if (pi == pnext) {
                    return "NO"; // Inconsistency found
                }
            }
        }
        
        return "YES"; // No inconsistencies found
    }
};


#endif