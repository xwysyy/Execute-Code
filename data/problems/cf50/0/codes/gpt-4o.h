#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;
        if (n == 1) return a[0] + 1;

        vector<int> dp(n, 0);
        // Base cases
        dp[0] = a[0] + 1; // Only the first item case
        if(n > 1) dp[1] = std::max(dp[0], a[1] + 1); // Compare first and second item

        // Fill dp table
        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i-1], a[i] + 1 + dp[i-2]);
        }

        return dp[n-1];
    }
};


#endif