#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n);
        
        for (int k = 1; k <= n; k++) {
            // For each prefix of length k
            double maxScore = 1.0;  // Score of empty subsequence
            int maxLen = 0;
            
            // Try all possible lengths of subsequences
            for (int len = 1; len <= k; len++) {
                // Calculate score using last 'len' elements of current prefix
                double score = 1.0;
                int factorial = 1;
                
                for (int i = 0; i < len; i++) {
                    score *= a[k - 1 - i];
                    factorial *= (i + 1);
                }
                score /= factorial;
                
                if (score > maxScore) {
                    maxScore = score;
                    maxLen = len;
                } else if (abs(score - maxScore) < 1e-10) {
                    maxLen = max(maxLen, len);
                }
            }
            
            result[k-1] = maxLen;
        }
        
        return result;
    }
};


#endif