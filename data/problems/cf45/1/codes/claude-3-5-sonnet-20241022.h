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
        for (int start = 0; start < n; start++) {
            int baseVal = a[start];  // Base value for the sequence
            long long cost = 0;
            int count = 0;
            
            // Count how many consecutive flowers we can take
            for (int j = start; j < n; j++) {
                if (a[j] - baseVal > 1) break;  // Difference exceeds 1
                cost += a[j];
                if (cost > m) break;  // Exceeded budget
                count++;
                maxPetals = max(maxPetals, accumulate(a.begin() + j - count + 1, 
                                                     a.begin() + j + 1, 0LL));
            }
        }
        
        return maxPetals;
    }
};


#endif