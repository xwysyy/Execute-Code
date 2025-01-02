#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {   
        // Sort the array to simplify finding groups of flower petal counts
        sort(a.begin(), a.end());
        
        long long maxPetals = 0;

        // We will use a sliding window approach to check groups of consecutive petal counts
        for (int i = 0; i < n; i++) {
            // We will consider a flower with 'a[i]' petals as the lower bound
            int lower = a[i];
            int upper = lower + 1;

            // Initialize total petals and total cost to 0
            long long totalPetals = 0;
            long long totalCost = 0;

            // Count flowers with 'lower' petals and flowers with 'upper' petals
            for (int j = i; j < n; j++) {
                if (a[j] == lower) {
                    totalPetals += lower;
                    totalCost += lower;
                } else if (a[j] == upper) {
                    totalPetals += upper;
                    totalCost += upper;
                } else {
                    break; // Break out of the loop if we encounter a petal count skipping the defined range
                }

                // Check if the current total cost exceeds the budget m
                if (totalCost > m) {
                    // If over budget, we cannot afford more flowers, we can break here
                    break;
                }

                // Update the maximum petals that can be bought
                maxPetals = max(maxPetals, totalPetals);
            }
        }

        return maxPetals;
    }
};


#endif