#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        vector<vector<int>> table(n, vector<int>(n));
        
        // Build the table with cyclic shifts
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate position after cyclic shift
                int pos = (j + i) % n;
                table[i][j] = s[pos] - '0';
            }
        }
        
        // For each column, calculate heights of consecutive 1's
        vector<vector<int>> heights(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (table[i][j] == 1) {
                    heights[i][j] = (i > 0) ? heights[i-1][j] + 1 : 1;
                }
            }
        }
        
        // For each row, find largest rectangle using histogram approach
        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            vector<int> left(n), right(n);
            stack<int> st;
            
            // Find left boundary
            for (int j = 0; j < n; j++) {
                while (!st.empty() && heights[i][st.top()] >= heights[i][j]) {
                    st.pop();
                }
                left[j] = st.empty() ? 0 : st.top() + 1;
                st.push(j);
            }
            
            // Clear stack for right boundary
            while (!st.empty()) st.pop();
            
            // Find right boundary
            for (int j = n-1; j >= 0; j--) {
                while (!st.empty() && heights[i][st.top()] >= heights[i][j]) {
                    st.pop();
                }
                right[j] = st.empty() ? n-1 : st.top() - 1;
                st.push(j);
            }
            
            // Calculate maximum area for current row
            for (int j = 0; j < n; j++) {
                if (heights[i][j] > 0) {
                    long long area = (long long)heights[i][j] * (right[j] - left[j] + 1);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};


#endif