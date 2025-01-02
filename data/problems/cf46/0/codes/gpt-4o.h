#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        // If there's only one column, we can't create 3 regions
        if (n == 1) return 0;

        // Auxiliary arrays
        vector<int> parent(2 * n), size(2 * n, 1);
        for (int i = 0; i < 2 * n; i++) parent[i] = i;
        
        // Union-Find (Disjoint Set Union) helper functions
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }

        // Initial connections in the graph
        for (int i = 0; i < n; i++) {
            if (s1[i] == '.' && s2[i] == '.') {
                unite(i, n + i);
            }
            if (i > 0) {
                if (s1[i] == '.' && s1[i - 1] == '.') {
                    unite(i - 1, i);
                }
                if (s2[i] == '.' && s2[i - 1] == '.') {
                    unite(n + i - 1, n + i);
                }
            }
        }

        // Function to count existing connected components
        int countComponents() {
            vector<bool> seen(2 * n, false);
            int compCount = 0;
            for (int i = 0; i < 2 * n; i++) {
                if ((i < n && s1[i] == '.') || (i >= n && s2[i - n] == '.')) {
                    int root = find(i);
                    if (!seen[root]) {
                        seen[root] = true;
                        compCount++;
                    }
                }
            }
            return compCount;
        }

        int initialComponentCount = countComponents();
        int countValidCells = 0;

        // Try blocking each cell and count the number of components
        for (int i = 0; i < n; i++) {
            if (s1[i] == '.') {
                s1[i] = 'x';
                int componentsOnBlocking = countComponents();
                if (componentsOnBlocking == 3) {
                    countValidCells++;
                }
                s1[i] = '.';
            }
            if (s2[i] == '.') {
                s2[i] = 'x';
                int componentsOnBlocking = countComponents();
                if (componentsOnBlocking == 3) {
                    countValidCells++;
                }
                s2[i] = '.';
            }
        }

        return countValidCells;
    }
};


#endif