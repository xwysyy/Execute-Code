#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, std::vector<int> &a) {
        // Use a set to identify unique elements
        std::set<int> uniqueElements(a.begin(), a.end());
        
        // Convert set to sorted vector to have ordered unique elements
        std::vector<int> uniqueVec(uniqueElements.begin(), uniqueElements.end());
        int uniqueCount = uniqueVec.size();
        
        // Calculate the minimum cost
        long long minCost = LLONG_MAX;
        
        for (int m = 1; m <= uniqueCount; ++m) {
            // Here m is the length of the target permutation
            
            // Calculate the number of removals needed
            long long removals = uniqueCount - m;
            long long removalCost = removals * (long long)c;
            
            // Find the number of insertions needed
            long long insertions = 0;
            for (int i = 1, j = 0; i <= m; ++i) {
                if (j < uniqueCount && uniqueVec[j] == i) {
                    ++j;
                } else {
                    ++insertions;
                }
            }
            long long insertionCost = insertions * (long long)d;
            
            // Total cost for this particular m
            long long totalCost = removalCost + insertionCost;
            
            // Update the minimum cost found
            if (totalCost < minCost) {
                minCost = totalCost;
            }
        }
        
        return minCost;
    }
};


#endif