#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {   
        int n = s.length();
        vector<vector<int>> table(n, vector<int>(n, 0));

        // Construct the cyclic shift table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                table[i][j] = s[(j + i) % n] - '0'; // Fill 0s and 1s based on shift
            }
        }

        long long maxArea = 0;

        // Iterate over each row to find the largest rectangle made of 1s
        for (int row = 0; row < n; ++row) {
            vector<int> heights(n, 0);
            for (int col = 0; col < n; ++col) {
                heights[col] = (table[row][col] == 1) ? (heights[col] + 1) : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    long long largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        long long maxArea = 0;
        heights.push_back(0); // Sentinel
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, (long long)height * width);
            }
            st.push(i);
        }
        heights.pop_back(); // Remove the sentinel
        return maxArea;
    }
};


#endif