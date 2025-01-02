#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        if (n == 1) return a[0] + 1;
        
        int dp[n][2]; // dp[i][0] = max score without coloring a[i], dp[i][1] = max score with coloring a[i]
        dp[0][0] = 0; // not choosing the first element
        dp[0][1] = a[0] + 1; // choosing the first element
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]); // not choosing a[i]
            dp[i][1] = dp[i-1][0] + a[i] + 1; // choosing a[i], so previous one cannot be chosen
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


#endif