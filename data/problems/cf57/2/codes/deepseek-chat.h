#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Create a map to group bottles by their brand
        unordered_map<int, vector<int>> brandToCosts;
        for (auto &bottle : b) {
            brandToCosts[bottle.first].push_back(bottle.second);
        }
        
        // For each brand, sort the costs in descending order
        vector<int> topCosts;
        for (auto &[brand, costs] : brandToCosts) {
            sort(costs.rbegin(), costs.rend());
            // Take the top n costs for each brand
            for (int i = 0; i < min(n, (int)costs.size()); ++i) {
                topCosts.push_back(costs[i]);
            }
        }
        
        // Sort all top costs in descending order
        sort(topCosts.rbegin(), topCosts.rend());
        
        // Take the top n costs overall
        int total = 0;
        for (int i = 0; i < min(n, (int)topCosts.size()); ++i) {
            total += topCosts[i];
        }
        
        return total;
    }
};


#endif