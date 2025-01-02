#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        map<int, priority_queue<int>> brand_costs;
        
        // Group bottles by brand and store their costs in a max-heap
        for (auto &p : b) {
            brand_costs[p.first].push(p.second);
        }
        
        // Sort the brands by the number of bottles available in descending order
        vector<pair<int, int>> sorted_brands;
        for (auto &p : brand_costs) {
            sorted_brands.push_back({p.second.size(), p.first});
        }
        sort(sorted_brands.rbegin(), sorted_brands.rend());
        
        int total_earnings = 0;
        int shelves_used = 0;
        
        // Place the most expensive bottles on the shelves
        for (auto &p : sorted_brands) {
            int count = p.first;
            int brand = p.second;
            while (count > 0 && shelves_used < n) {
                total_earnings += brand_costs[brand].top();
                brand_costs[brand].pop();
                count--;
                shelves_used++;
            }
        }
        
        return total_earnings;
    }
};

#endif