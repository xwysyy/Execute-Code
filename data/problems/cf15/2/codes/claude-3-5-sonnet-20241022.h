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
            
            // Try all possible subsequences
            for (int len = 1; len <= k; len++) {
                // Calculate score for subsequences of length len
                double score = 1.0;
                int count = 0;
                
                // Get last 'len' elements as they will give maximum product
                for (int i = k - len; i < k; i++) {
                    score *= a[i];
                    count++;
                }
                
                // Calculate factorial
                double factorial = 1.0;
                for (int i = 1; i <= len; i++) {
                    factorial *= i;
                }
                
                score /= factorial;
                
                // Update maxScore and maxLen if current score is larger
                if (score > maxScore + 1e-9) {
                    maxScore = score;
                    maxLen = len;
                }
                // If scores are equal, take the longer subsequence
                else if (abs(score - maxScore) < 1e-9) {
                    maxLen = max(maxLen, len);
                }
            }
            
            result[k-1] = maxLen;
        }
        
        return result;
    }
};


#endif