#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        if (n == 0) return 0;

        // Create the n x n table
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = s[(j - i + n) % n] - '0';
            }
        }

        // Function to calculate the maximum area in a histogram
        auto maxAreaInHistogram = [](vector<int> &heights) -> long long {
            stack<int> st;
            long long maxArea = 0;
            int i = 0;
            while (i < heights.size()) {
                if (st.empty() || heights[st.top()] <= heights[i]) {
                    st.push(i++);
                } else {
                    int top = st.top();
                    st.pop();
                    long long area = heights[top] * (st.empty() ? i : i - st.top() - 1);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                long long area = heights[top] * (st.empty() ? i : i - st.top() - 1);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            return maxArea;
        };

        // Calculate the maximum area in the table
        long long maxArea = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (table[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            long long area = maxAreaInHistogram(heights);
            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};


#endif