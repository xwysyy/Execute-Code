#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {   
        vector<int> dp(V + 1, 0); // Initialize a dp array with size V+1 and all values 0.

        for (int i = 0; i < N; ++i) {
            // We update dp array backwards to prevent overwriting values we still need to consider.
            for (int j = V; j >= v[i]; --j) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        
        // The result will be the maximum value we can achieve with the full capacity V.
        return dp[V];
    }
};


#endif