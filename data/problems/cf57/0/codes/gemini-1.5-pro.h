#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        map<int, vector<int>> bottles_by_brand;
        for (const auto& bottle : b) {
            bottles_by_brand[bottle.first].push_back(bottle.second);
        }

        vector<long long> shelf_values;
        for (auto& entry : bottles_by_brand) {
            sort(entry.second.rbegin(), entry.second.rend());
            long long current_shelf_value = 0;
            for (int cost : entry.second) {
                current_shelf_value += cost;
                shelf_values.push_back(current_shelf_value);
            }
        }

        sort(shelf_values.rbegin(), shelf_values.rend());

        long long max_earnings = 0;
        for (int i = 0; i < min((int)shelf_values.size(), n); ++i) {
            max_earnings += shelf_values[i];
        }

        return max_earnings;
    }
};


#endif