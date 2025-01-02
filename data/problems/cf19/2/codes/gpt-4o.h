#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(std::string &s) {
        int n = s.size();
        std::vector<int> height(n, 0);
        long long max_area = 0;

        // Process each cyclic shift as a start
        for (int start = 0; start < n; ++start) {
            // Calculate the histogram height for each column
            for (int i = 0; i < n; ++i) {
                if (s[(i + start) % n] == '1') {
                    height[i]++;
                } else {
                    height[i] = 0;
                }
            }

            // Calculate the maximum rectangle area in this histogram
            max_area = std::max(max_area, largestRectangleArea(height));
        }

        return max_area;
    }
    
private:
    long long largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> st;
        long long max_area = 0;
        
        for (int i = 0; i <= n; ++i) {
            int current_height = (i == n ? 0 : heights[i]);
            while (!st.empty() && current_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                max_area = std::max(max_area, (long long) h * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};


#endif