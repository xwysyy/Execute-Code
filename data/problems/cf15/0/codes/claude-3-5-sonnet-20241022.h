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
            double maxScore = 1.0; // Score of empty subsequence
            int maxLen = 0;
            
            // Try all possible subsequence lengths
            for (int len = 1; len <= k; len++) {
                // Calculate score for subsequences ending at position k-1
                double prod = 1.0;
                int factorial = 1;
                
                // Take the last 'len' elements that give maximum product
                for (int i = k - len; i < k; i++) {
                    prod *= a[i];
                    factorial *= (i - (k - len) + 1);
                }
                
                double score = prod / factorial;
                
                if (score > maxScore + 1e-9) { // Use epsilon for floating point comparison
                    maxScore = score;
                    maxLen = len;
                } else if (abs(score - maxScore) < 1e-9) {
                    maxLen = max(maxLen, len);
                }
            }
            
            result[k-1] = maxLen;
        }
        
        return result;
    }
};


#endif