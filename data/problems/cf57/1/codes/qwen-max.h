#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Sort the bottles by their cost in descending order
        sort(b.begin(), b.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });

        // Map to store the maximum number of bottles that can be placed for each brand
        unordered_map<int, int> brand_count;
        int total_earnings = 0;

        // Iterate through the sorted bottles
        for (auto &p : b) {
            int brand = p.first;
            int cost = p.second;

            // If the brand is not in the map, add it with the maximum count
            if (brand_count.find(brand) == brand_count.end()) {
                brand_count[brand] = min(n, (int)b.size());
            }

            // If there are still shelves available for this brand, place the bottle and update the count
            if (brand_count[brand] > 0) {
                total_earnings += cost;
                brand_count[brand]--;
                n--;
            }

            // If all shelves are filled, break the loop
            if (n == 0) {
                break;
            }
        }

        return total_earnings;
    }
};

#endif