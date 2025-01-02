#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.size();
        vector<int> height(n, 0);
        long long maxArea = 0;

        // Iterate over each row (each cyclic shift)
        for (int i = 0; i < n; i++) {
            // Update heights based on the cyclic shift
            for (int j = 0; j < n; j++) {
                // Calculate the original index accounting for the cyclic shift
                int originalIndex = (j + i) % n;
                height[j] = (s[originalIndex] == '1') ? height[j] + 1 : 0;
            }

            // Calculate max rectangle area for the current heights
            maxArea = max(maxArea, maxRectangleArea(height));
        }

        return maxArea;
    }

private:
    long long maxRectangleArea(vector<int>& heights) {
        stack<int> stk;
        long long maxArea = 0;
        heights.push_back(0); // Add a sentinel to flush the stack at the end

        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, (long long)h * width);
            }
            stk.push(i);
        }
        
        return maxArea;
    }
};


#endif