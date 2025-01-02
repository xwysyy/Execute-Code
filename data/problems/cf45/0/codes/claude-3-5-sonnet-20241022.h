#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        // Sort the array to group similar petal counts
        sort(a.begin(), a.end());
        
        long long maxPetals = 0;
        
        // Try each possible starting position
        for (int i = 0; i < n; i++) {
            int start = a[i];  // Starting petal count
            long long cost = 0;
            int count = 0;
            
            // Count how many flowers we can buy starting from this position
            for (int j = i; j < n; j++) {
                // If difference in petals is more than 1, break
                if (a[j] - start > 1) break;
                
                cost += a[j];
                if (cost > m) break;  // If cost exceeds budget, break
                
                count++;
                maxPetals = max(maxPetals, accumulate(a.begin() + j - count + 1, 
                                                    a.begin() + j + 1, 0LL));
            }
        }
        
        return maxPetals;
    }
};


#endif