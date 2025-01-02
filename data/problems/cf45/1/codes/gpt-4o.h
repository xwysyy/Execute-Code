#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {   
        // Step 1: Sort the petals
        sort(a.begin(), a.end());
        
        long long maxPetals = 0;
        
        // Step 2: Two pointers technique to find the largest possible bouquet under given constraints
        int start = 0;
        long long currentCost = 0;
        long long currentPetals = 0;
        
        for (int end = 0; end < n; ++end) {
            // When adding a[end], update the cost and petals
            currentCost += a[end];
            currentPetals += a[end];
            
            // Check if we need to shrink the range to satisfy the petal difference condition
            while (a[end] - a[start] > 1) {
                currentCost -= a[start];
                currentPetals -= a[start];
                ++start;
            }
            
            // Check if the current selection is feasible (i.e., the cost doesn't exceed m)
            if (currentCost <= m) {
                maxPetals = max(maxPetals, currentPetals);
            }
        }
        
        // Return the maximum petals found
        return maxPetals;
    }
};


#endif