#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        if (n == 1) return a[0] + 1;
        
        vector<int> dp(n, 0);
        dp[0] = a[0] + 1;
        dp[1] = max(a[1] + 1, dp[0]);
        
        int maxElement = max(a[0], a[1]);
        
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + a[i] + 1);
            maxElement = max(maxElement, a[i]);
        }
        
        return max(dp[n-1], maxElement + (int)ceil(n/2.0));
    }
};


#endif