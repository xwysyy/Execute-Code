#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Initial number of inversions
        long long currentInversions = 0;
        int numOfOnes = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                currentInversions += numOfOnes;
            } else {
                numOfOnes++;
            }
        }
        
        // Calculate max inversions by flipping one element
        // Potential inversion counts by considering flips
        long long maxInversions = currentInversions;
        int leadingOnes = 0;
        long long potentialInversions = 0;

        // Consider flipping each element
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                // Flip current 0 to 1
                potentialInversions = currentInversions + leadingOnes - (numOfOnes - leadingOnes);
            } else {
                // Flip current 1 to 0
                potentialInversions = currentInversions - leadingOnes + (numOfOnes - leadingOnes - 1);
                leadingOnes++;
            }
            
            maxInversions = max(maxInversions, potentialInversions);
        }
        
        return maxInversions;
    }
};


#endif