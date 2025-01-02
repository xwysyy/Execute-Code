#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.size();
        vector<int> heights(n, 0);
        long long maxArea = 0;
        
        for (int k = 0; k < n; ++k) {
            // Compute heights for the k-th cyclic shift
            for (int i = 0; i < n; ++i) {
                // Calculate the actual cyclic position
                int pos = (i + k) % n;
                heights[i] = (s[pos] == '1') ? heights[i] + 1 : 0;
            }
            // Calculate the maximum rectangle area for the current heights
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
    
    long long largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        long long maxArea = 0;
        heights.push_back(0); // Add a sentinel value to pop all remaining bars
        
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, (long long)h * width);
            }
            st.push(i);
        }
        heights.pop_back(); // Remove sentinel value
        return maxArea;
    }
};


#endif