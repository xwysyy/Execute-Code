#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        unordered_set<int> uniqueElements(a.begin(), a.end());
        int maxElement = *max_element(a.begin(), a.end());
        int uniqueCount = uniqueElements.size();
        
        // If all elements are unique and form a permutation, no cost is needed
        if (uniqueCount == n && maxElement == n) {
            return 0;
        }
        
        // Calculate the cost to remove all elements
        long long removeCost = (long long)n * c;
        
        // Calculate the cost to make the array a permutation
        long long minCost = removeCost + d;  // Remove all and add one element
        for (int i = 1; i <= n; ++i) {
            int currentMax = max(maxElement, i);
            int requiredInsertions = currentMax - uniqueCount;
            long long currentCost = (long long)(n - uniqueCount) * c + (long long)requiredInsertions * d;
            minCost = min(minCost, currentCost);
        }
        
        return minCost;
    }
};

#endif