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
            int baseVal = a[start];  // Base value for petal count
            long long cost = 0;
            int count = 0;
            
            // Count how many flowers we can take with petals of baseVal or baseVal+1
            for (int i = start; i < n; i++) {
                if (a[i] > baseVal + 1) break;
                cost += a[i];
                if (cost <= m) {
                    count++;
                    maxPetals = max(maxPetals, accumulate(a.begin() + start, a.begin() + start + count, 0LL));
                } else {
                    break;
                }
            }
        }
        
        return maxPetals;
    }
};


#endif