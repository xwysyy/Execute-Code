#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        // First, find the connected regions in the grid
        // Since the grid contains at most 1 connected region, we can assume that initially, all free cells are connected
        // We need to find cells that, when blocked, split the connected region into exactly 3 regions

        // To achieve this, we can iterate through each cell and check if blocking it would split the region into 3
        // However, this approach would be too slow for n up to 1e6
        // Instead, we can look for specific patterns where blocking a cell would split the region into 3

        // One such pattern is when a cell is a bridge between two parts of the grid
        // For example, if a cell is the only connection between two larger regions, blocking it would split the grid into 3 regions

        // We can use a Union-Find (Disjoint Set Union) data structure to help us identify such cells
        // First, we initialize the Union-Find structure with all free cells
        // Then, we iterate through each cell and check if it is a bridge

        // However, implementing Union-Find for this problem is complex and may not be necessary
        // Instead, we can look for specific patterns in the grid that indicate a cell is a bridge

        // For example, if a cell is the only connection between two larger regions, it must be in a position where it is the only free cell in its column and both rows

        // Let's implement this logic

        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.' && s2[i] == '.') {
                // Check if this cell is the only connection between two regions
                // We can check if the cells to the left and right are blocked
                bool leftBlocked = (i == 0 || (s1[i-1] == 'x' && s2[i-1] == 'x'));
                bool rightBlocked = (i == n-1 || (s1[i+1] == 'x' && s2[i+1] == 'x'));

                if (leftBlocked && rightBlocked) {
                    // This cell is the only connection between two regions
                    count++;
                }
            }
        }

        return count;
    }
};


#endif