#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Create a map to store the total cost for each brand
        unordered_map<int, int> brandCost;
        
        // Calculate the total cost for each brand
        for (auto &p : b) {
            brandCost[p.first] += p.second;
        }
        
        // Use a priority queue to get the top n brands with the highest total cost
        priority_queue<int> maxHeap;
        for (auto &entry : brandCost) {
            maxHeap.push(entry.second);
        }
        
        // Calculate the maximum amount that can be earned by selecting up to n shelves
        int maxEarnings = 0;
        for (int i = 0; i < n && !maxHeap.empty(); ++i) {
            maxEarnings += maxHeap.top();
            maxHeap.pop();
        }
        
        return maxEarnings;
    }
};


#endif