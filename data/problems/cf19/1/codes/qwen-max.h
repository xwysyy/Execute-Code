#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.length();
        vector<int> height(n, 0);
        long long max_area = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                height[i] = 1;
            } else {
                height[i] = 0;
            }
        }
        
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (s[(i + k) % n] == '1') {
                    height[i]++;
                } else {
                    height[i] = 0;
                }
            }
            
            // Calculate the maximum area for the current column heights
            stack<int> st;
            for (int i = 0; i <= n; ++i) {
                while (!st.empty() && (i == n || height[st.top()] >= height[i])) {
                    int h = height[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i - st.top() - 1;
                    max_area = max(max_area, (long long)h * w);
                }
                st.push(i);
            }
        }
        
        return max_area;
    }
};


#endif