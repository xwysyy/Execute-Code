#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(std::string &s) {   
        int n = s.size();
        std::vector<int> heights(n, 0);
        long long max_area = 0;
        
        // Lambda function to get maximum rectangle area in a histogram
        auto largestRectangleArea = [](const std::vector<int>& heights) -> long long {
            std::stack<int> st;
            int n = heights.size();
            std::vector<int> left(n), right(n);
            long long max_area = 0;
            
            // Calculating the first smaller element on the left
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                left[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            
            while (!st.empty()) st.pop();
            
            // Calculating the first smaller element on the right
            for (int i = n - 1; i >= 0; --i) {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                right[i] = st.empty() ? n : st.top();
                st.push(i);
            }
            
            // Calculating the maximum area
            for (int i = 0; i < n; ++i) {
                long long width = right[i] - left[i] - 1;
                long long area = heights[i] * width;
                max_area = std::max(max_area, area);
            }
            return max_area;
        };
        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                // Calculate the real index in s when considering the cyclic shift
                int real_index = (col - row + n) % n;
                if (s[real_index] == '1') {
                    heights[col] += 1;
                } else {
                    heights[col] = 0;
                }
            }
            // Update max_area with largest area from current row
            max_area = std::max(max_area, largestRectangleArea(heights));
        }
        
        return max_area;
    }
};


#endif