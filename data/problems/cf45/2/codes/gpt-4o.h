#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, std::vector<int> &a) {   
        // Sort the list of petals.
        std::sort(a.begin(), a.end());
        
        long long maxPetals = 0;
        long long currentPetals = 0;
        long long currentCost = 0;
        
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // Add current flower's petals and cost.
            currentPetals += a[right];
            currentCost += a[right];
            
            // Adjust the window to ensure the cost does not exceed m
            // and the valid petals condition
            while (currentCost > m || (a[right] - a[left] > 1)) {
                // Remove the left-most flower from the current window
                currentPetals -= a[left];
                currentCost -= a[left];
                left++;
            }
            
            // Check if the current valid window offers max petals
            maxPetals = std::max(maxPetals, currentPetals);
        }
        
        return maxPetals;
    }
};


#endif