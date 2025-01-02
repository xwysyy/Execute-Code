#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        // Frequency map to count occurrences of each petal count
        unordered_map<int, long long> petalCount;
        for (int petals : a) {
            petalCount[petals]++;
        }

        // Convert the map back to a sorted vector of unique flower petal counts
        vector<int> uniquePetals;
        for (const auto &entry : petalCount) {
            uniquePetals.push_back(entry.first);
        }
        sort(uniquePetals.begin(), uniquePetals.end());

        long long maxPetals = 0;

        // Iterate through the unique petal counts
        for (size_t i = 0; i < uniquePetals.size(); ++i) {
            int currentPetal = uniquePetals[i];

            // Number of flowers with `currentPetal` petals
            long long countCurrent = petalCount[currentPetal];

            // Try to buy only current petals
            long long totalCost = currentPetal * countCurrent;
            if (totalCost <= m) {
                maxPetals = max(maxPetals, totalCost);
            }

            // Try to buy currentPetal and currentPetal + 1 if possible
            // Only process the next petal count if it exists
            if (i + 1 < uniquePetals.size() && uniquePetals[i + 1] == currentPetal + 1) {
                int nextPetal = uniquePetals[i + 1];
                long long countNext = petalCount[nextPetal];

                // Total petals if we take both current and next petal counts
                long long additionalPetals = countCurrent + countNext;
                long long totalCostWithNext = (currentPetal * countCurrent) + (nextPetal * countNext);

                // Use binary search or two pointers to find how many of each we can take
                long long left = 0, right = additionalPetals;
                while (left <= right) {
                    long long mid = left + (right - left) / 2;
                    long long cost = (mid * currentPetal) + ((additionalPetals - mid) * nextPetal);
                    if (cost <= m) {
                        maxPetals = max(maxPetals, mid * currentPetal + (additionalPetals - mid) * nextPetal);
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        return maxPetals;
    }
};


#endif