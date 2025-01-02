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
        
        // Use a priority queue to get the brands with the highest total cost
        priority_queue<pair<int, int>> maxHeap;
        for (auto &entry : brandCost) {
            maxHeap.push({entry.second, entry.first});
        }
        
        int maxEarnings = 0;
        // Take the top n brands from the heap
        for (int i = 0; i < n && !maxHeap.empty(); ++i) {
            maxEarnings += maxHeap.top().first;
            maxHeap.pop();
        }
        
        return maxEarnings;
    }
};


#endif