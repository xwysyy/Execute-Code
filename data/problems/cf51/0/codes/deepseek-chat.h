#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;
        
        vector<int> dp(n, 1); // dp[i] will store the length of the longest non-increasing subsequence ending at i
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] <= a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        int max_length = *max_element(dp.begin(), dp.end());
        return n - max_length;
    }
};


#endif