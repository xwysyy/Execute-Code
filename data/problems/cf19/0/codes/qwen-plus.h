#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.size();
        vector<int> height(n, 0);
        long long maxArea = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> currHeight = height;
            if (s[i] == '1') {
                currHeight[i]++;
            }
            for (int j = 0; j < n; ++j) {
                if (s[(i + j) % n] == '1') {
                    currHeight[j]++;
                } else {
                    currHeight[j] = 0;
                }
            }

            // Calculate the largest rectangle area in histogram for current row
            vector<int> left(n), right(n);
            stack<int> st;

            // Calculate left boundary
            for (int j = 0; j < n; ++j) {
                while (!st.empty() && currHeight[st.top()] >= currHeight[j]) {
                    st.pop();
                }
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }

            // Clear the stack to reuse for right boundary
            while (!st.empty()) st.pop();

            // Calculate right boundary
            for (int j = n - 1; j >= 0; --j) {
                while (!st.empty() && currHeight[st.top()] >= currHeight[j]) {
                    st.pop();
                }
                right[j] = st.empty() ? n : st.top();
                st.push(j);
            }

            // Calculate maximum area for current row
            for (int j = 0; j < n; ++j) {
                maxArea = max(maxArea, static_cast<long long>(currHeight[j]) * (right[j] - left[j] - 1));
            }

            height = currHeight;
        }

        return maxArea;
    }
};


#endif