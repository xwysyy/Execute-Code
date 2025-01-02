#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Group bottles by brand and sort each group in descending order of cost
        map<int, vector<int>> brandToCosts;
        for (auto &bottle : b) {
            brandToCosts[bottle.first].push_back(bottle.second);
        }
        
        // For each brand, sort the costs in descending order
        for (auto &brand : brandToCosts) {
            sort(brand.second.rbegin(), brand.second.rend());
        }
        
        // Collect the top n shelves' costs
        vector<int> topCosts;
        for (auto &brand : brandToCosts) {
            for (int cost : brand.second) {
                topCosts.push_back(cost);
            }
        }
        
        // Sort all costs in descending order
        sort(topCosts.rbegin(), topCosts.rend());
        
        // Sum the top n costs
        int sum = 0;
        for (int i = 0; i < min(n, (int)topCosts.size()); ++i) {
            sum += topCosts[i];
        }
        
        return sum;
    }
};


#endif