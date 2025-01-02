#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        map<int, vector<int>> bottlesByBrand;
        for (const auto& bottle : b) {
            bottlesByBrand[bottle.first].push_back(bottle.second);
        }

        vector<int> shelfValues;
        for (auto& entry : bottlesByBrand) {
            sort(entry.second.rbegin(), entry.second.rend());
            int currentShelfValue = 0;
            for (int cost : entry.second) {
                currentShelfValue += cost;
                shelfValues.push_back(currentShelfValue);
            }
        }

        sort(shelfValues.rbegin(), shelfValues.rend());

        int totalEarnings = 0;
        for (int i = 0; i < min((int)shelfValues.size(), n); ++i) {
            totalEarnings += shelfValues[i];
        }

        return totalEarnings;
    }
};


#endif