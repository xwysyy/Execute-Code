#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Construct the table
        vector<string> table(n);
        for (int i = 0; i < n; ++i) {
            table[i] = s.substr(n - i) + s.substr(0, n - i);
        }
        
        long long maxArea = 0;
        
        // For each column, treat it as a histogram
        for (int col = 0; col < n; ++col) {
            vector<int> heights(n);
            for (int row = 0; row < n; ++row) {
                if (table[row][col] == '1') {
                    heights[row] = (row == 0) ? 1 : heights[row - 1] + 1;
                } else {
                    heights[row] = 0;
                }
            }
            
            // Use stack to find the largest rectangle in the histogram
            stack<int> st;
            long long area = 0;
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && heights[st.top()] > heights[i]) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i - st.top() - 1;
                    area = max(area, (long long)h * w);
                }
                st.push(i);
            }
            while (!st.empty()) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? n : n - st.top() - 1;
                area = max(area, (long long)h * w);
            }
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};


#endif