#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        // First, find the connected regions in the grid
        // Since there is at most one connected region, we can find all free cells
        // and then check for each free cell if blocking it would create exactly 3 connected regions
        
        // Collect all free cells
        vector<pair<int, int>> freeCells;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '.') freeCells.push_back({0, i});
            if (s2[i] == '.') freeCells.push_back({1, i});
        }
        
        // If there are no free cells, return 0
        if (freeCells.empty()) return 0;
        
        // Now, for each free cell, simulate blocking it and check the number of connected regions
        int result = 0;
        for (auto &cell : freeCells) {
            int row = cell.first;
            int col = cell.second;
            
            // Simulate blocking the cell
            string temp1 = s1;
            string temp2 = s2;
            if (row == 0) temp1[col] = 'x';
            else temp2[col] = 'x';
            
            // Now, count the number of connected regions
            vector<vector<bool>> visited(2, vector<bool>(n, false));
            int regions = 0;
            for (int i = 0; i < n; ++i) {
                if (temp1[i] == '.' && !visited[0][i]) {
                    dfs(0, i, temp1, temp2, visited);
                    regions++;
                }
                if (temp2[i] == '.' && !visited[1][i]) {
                    dfs(1, i, temp1, temp2, visited);
                    regions++;
                }
            }
            
            if (regions == 3) result++;
        }
        
        return result;
    }
    
private:
    void dfs(int row, int col, string &s1, string &s2, vector<vector<bool>> &visited) {
        if (row < 0 || row >= 2 || col < 0 || col >= s1.length() || visited[row][col]) return;
        if ((row == 0 && s1[col] == 'x') || (row == 1 && s2[col] == 'x')) return;
        
        visited[row][col] = true;
        
        // Explore all four directions
        dfs(row + 1, col, s1, s2, visited);
        dfs(row - 1, col, s1, s2, visited);
        dfs(row, col + 1, s1, s2, visited);
        dfs(row, col - 1, s1, s2, visited);
    }
};


#endif