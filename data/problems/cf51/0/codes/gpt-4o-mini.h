#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> dp(n, 1);
        
        for(int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        
        int max_length = *max_element(dp.begin(), dp.end());
        return n - max_length;
    }
};


#endif