#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &N, int &V, vector<int> &v, vector<int> &w) {   
        vector<int> dp(V + 1, 0); // DP array to store the maximum value for each capacity
        
        for (int i = 0; i < N; i++) { // Iterate through each item
            for (int j = V; j >= v[i]; j--) { // Iterate the capacities in reverse
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]); // Update the maximum value
            }
        }
        
        return dp[V]; // The maximum value that can be carried with capacity V
    }
};


#endif