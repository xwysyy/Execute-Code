#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, std::vector<int> &a) {
        // Step 1: Sort the array of flowers by number of petals
        std::sort(a.begin(), a.end());
        
        // Step 2: Compute the prefix sums
        std::vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + a[i - 1];
        }
        
        // Step 3: Use sliding window technique to find the maximum petals bouquet
        long long maxPetals = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            // Ensure the difference in petals between first and last is <= 1
            while (a[r] - a[l] > 1) {
                l++;
            }
            // Calculate cost of the bouquet from l to r using prefix sums
            long long cost = prefixSum[r + 1] - prefixSum[l];
            if (cost <= m) {
                // Calculate number of petals in the bouquet
                long long petals = prefixSum[r + 1] - prefixSum[l];
                maxPetals = std::max(maxPetals, petals);
            }
        }
        
        return maxPetals;
    }
};


#endif