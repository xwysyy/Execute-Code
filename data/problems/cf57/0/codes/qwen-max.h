#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Sort bottles by brand and then by cost in descending order
        sort(b.begin(), b.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        // Map to store the maximum cost for each brand
        map<int, int> maxCostByBrand;
        for (auto &p : b) {
            maxCostByBrand[p.first] = max(maxCostByBrand[p.first], p.second);
        }

        // Vector to store the costs of the most expensive bottles for each brand
        vector<int> maxCosts;
        for (auto &p : maxCostByBrand) {
            maxCosts.push_back(p.second);
        }

        // Sort the costs in descending order
        sort(maxCosts.rbegin(), maxCosts.rend());

        // Calculate the maximum amount he can earn
        int totalEarnings = 0;
        for (int i = 0; i < min(n, (int)maxCosts.size()); ++i) {
            totalEarnings += maxCosts[i];
        }

        return totalEarnings;
    }
};

#endif