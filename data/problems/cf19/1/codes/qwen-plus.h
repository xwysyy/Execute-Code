#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        
        // Build the table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = s[(i + j) % n] - '0';
            }
        }

        // Calculate the largest rectangle of ones
        vector<int> height(n, 0);
        long long maxArea = 0;

        for (int i = 0; i < n; ++i) {
            stack<int> st;
            for (int j = 0; j <= n; ++j) {
                if (j < n) {
                    if (table[i][j] == 1) height[j]++;
                    else height[j] = 0;
                }
                while (!st.empty() && (j == n || height[st.top()] >= height[j])) {
                    int h = height[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, static_cast<long long>(h) * width);
                }
                if (j < n) st.push(j);
            }
        }

        return maxArea;
    }
};


#endif