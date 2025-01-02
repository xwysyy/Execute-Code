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
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = s[(j - i + n) % n] - '0';
            }
        }
        
        // Function to calculate the maximum area in a histogram
        auto maxHistogramArea = [](const vector<int>& row) -> long long {
            stack<int> st;
            long long maxArea = 0;
            int i = 0;
            while (i < row.size()) {
                if (st.empty() || row[st.top()] <= row[i]) {
                    st.push(i++);
                } else {
                    int top = st.top();
                    st.pop();
                    long long area = row[top] * (st.empty() ? i : i - st.top() - 1);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                long long area = row[top] * (st.empty() ? i : i - st.top() - 1);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            return maxArea;
        };
        
        // Calculate the maximum area for each row
        long long maxArea = 0;
        for (int i = 0; i < n; ++i) {
            long long area = maxHistogramArea(table[i]);
            if (area > maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};


#endif