#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int result = 0;
        vector<int> pie, mapSub;

        // Find all occurrences of "pie" and "map"
        for (int i = 0; i <= n - 3; ++i) {
            if (s.substr(i, 3) == "pie") pie.push_back(i);
            if (s.substr(i, 3) == "map") mapSub.push_back(i);
        }

        // Function to calculate minimum deletions using dynamic programming
        auto minDeletions = [&](vector<int>& indices) {
            int m = indices.size();
            vector<int> dp(m + 1, 0);

            for (int i = 1; i <= m; ++i) {
                dp[i] = dp[i - 1] + 1; // Remove this occurrence
                if (i > 1 && indices[i - 1] == indices[i - 2] + 3)
                    dp[i] = min(dp[i], dp[i - 2] + 1); // Remove one character to break the overlap
            }
            return dp[m];
        };

        result += minDeletions(pie);
        result += minDeletions(mapSub);

        return result;
    }
};


#endif