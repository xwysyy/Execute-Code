#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        unordered_map<int, long long> brandEarnings;

        // Step 1: Aggregate earnings for each brand
        for (const auto& bottle : b) {
            int brand = bottle.first;
            int cost = bottle.second;
            brandEarnings[brand] += cost; // Accumulate costs for the brand
        }

        // Step 2: Store aggregated earnings in a vector
        vector<long long> totalEarnings;
        for (const auto& entry : brandEarnings) {
            totalEarnings.push_back(entry.second);
        }

        // Step 3: Sort the earnings in descending order
        sort(totalEarnings.rbegin(), totalEarnings.rend());

        // Step 4: Sum the top `n` earnings
        long long maxEarnings = 0;
        for (int i = 0; i < min(n, (int)totalEarnings.size()); i++) {
            maxEarnings += totalEarnings[i];
        }

        return maxEarnings;
    }
};


#endif