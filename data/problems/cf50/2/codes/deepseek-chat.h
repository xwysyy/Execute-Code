#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;
        
        // dp[i][0] represents the maximum score up to index i without coloring a[i]
        // dp[i][1] represents the maximum score up to index i with coloring a[i]
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        
        dp[0][0] = 0;
        dp[0][1] = a[0] + 1;
        
        for (int i = 1; i < n; ++i) {
            // If we don't color a[i], we can take the maximum of the previous two states
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            
            // If we color a[i], we must not have colored a[i-1]
            dp[i][1] = dp[i-1][0] + a[i] + 1;
        }
        
        // The answer is the maximum of the last two states
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif