#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return a[0] + 1;
        if (n == 2) return std::max(a[0] + 1, a[1] + 1);

        int prev2 = a[0] + 1; // dp[0]
        int prev1 = std::max(a[0] + 1, a[1] + 1); // dp[1]
        
        int maxScore = prev1;

        for (int i = 2; i < n; ++i) {
            int current = std::max(prev1, a[i] + 1 + prev2);
            maxScore = current;
            prev2 = prev1;
            prev1 = current;
        }
        
        return maxScore;
    }
};


#endif