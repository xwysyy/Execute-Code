#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s) {
        int n = s.size();
        vector<int> hist(n, 0);
        long long maxArea = 0;

        for (int i = 0; i < n; ++i) {
            // Update histogram for the current row
            for (int j = 0; j < n; ++j) {
                if (s[(j + i) % n] == '1') {
                    hist[j]++;
                } else {
                    hist[j] = 0;
                }
            }

            // Calculate the largest rectangle in the histogram
            stack<int> st;
            for (int j = 0; j <= n; ++j) {
                while (!st.empty() && (j == n || hist[st.top()] >= hist[j])) {
                    int height = hist[st.top()];
                    st.pop();
                    int start = st.empty() ? -1 : st.top();
                    maxArea = max(maxArea, (long long)height * (j - start - 1));
                }
                if (j < n) st.push(j);
            }
        }

        return maxArea;
    }
};


#endif