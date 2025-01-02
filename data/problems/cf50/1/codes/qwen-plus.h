#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        if (n == 0) return 0;
        if (n == 1) return a[0] + 1;

        int maxRedValue = 0;
        int dp[n];
        dp[0] = a[0];
        maxRedValue = max(maxRedValue, a[0]);
        
        dp[1] = max(a[0], a[1]);
        maxRedValue = max(maxRedValue, a[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
            maxRedValue = max(maxRedValue, a[i]);
        }

        // The score is the maximum value of a red element plus the number of red elements.
        // We can calculate the number of red elements by checking how many times we take the value from dp[i-2] + a[i]
        int numRedElements = 0;
        int totalScore = dp[n-1];
        for (int i = n - 1; i >= 0; --i) {
            if (i == 0 || dp[i] == dp[i-2] + a[i]) {
                numRedElements++;
            }
        }

        return maxRedValue + numRedElements;
    }
};


#endif