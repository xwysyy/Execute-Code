#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        if (n == 0) return d;
        
        // Set to keep track of unique elements in the array
        set<int> uniqueElements(a.begin(), a.end());
        
        // If all elements are unique and form a permutation, no cost is needed
        if (uniqueElements.size() == n && *uniqueElements.rbegin() == n && *uniqueElements.begin() == 1) {
            return 0;
        }
        
        // Count how many numbers from 1 to n are missing
        int maxElement = *uniqueElements.rbegin();
        int minElement = *uniqueElements.begin();
        int missingCount = 0;
        for (int i = minElement; i <= maxElement; ++i) {
            if (uniqueElements.find(i) == uniqueElements.end()) {
                missingCount++;
            }
        }
        
        // Calculate the cost to insert missing elements
        long long insertCost = (long long)d * missingCount;
        
        // Calculate the cost to remove extra elements and make it a permutation
        int nonPermutationElements = n - uniqueElements.size();
        long long removeCost = (long long)c * nonPermutationElements;
        
        // Adjust remove cost if we need to remove elements greater than the size of the permutation
        int finalSize = uniqueElements.size() - missingCount;
        if (finalSize < 1) {
            finalSize = 1;
        }
        removeCost += (long long)c * (maxElement - finalSize);
        
        // Minimum cost is the minimum between inserting missing elements or removing extra elements
        long long minCost = min(insertCost, removeCost);
        
        // If the array has no valid permutation elements, consider the cost of making a single element permutation
        if (uniqueElements.empty()) {
            minCost = min(minCost, (long long)d);
        }
        
        return minCost;
    }
};


#endif