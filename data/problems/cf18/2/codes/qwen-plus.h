#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        // Remove duplicates and sort the array to handle permutations correctly
        set<int> uniqueElements(a.begin(), a.end());
        vector<int> sortedUnique(uniqueElements.begin(), uniqueElements.end());
        int m = sortedUnique.size();
        
        // If the array is already a permutation of size m, no operations needed
        if (m == 0) return min(c, d);
        
        // Check if the elements form a continuous sequence starting from 1
        bool isPermutation = true;
        for (int i = 0; i < m; ++i) {
            if (sortedUnique[i] != i + 1) {
                isPermutation = false;
                break;
            }
        }
        
        if (isPermutation) return 0;
        
        // Calculate the cost of making it a permutation
        long long removeCost = (long long)(n - m) * c;
        long long insertCost = 0;
        
        // Find the minimum number of insertions needed to make it a permutation
        int maxElement = sortedUnique.back();
        int minElement = sortedUnique.front();
        int requiredLength = maxElement;
        int missingCount = requiredLength - m;
        
        if (missingCount > 0) {
            insertCost = (long long)missingCount * d;
        } else {
            // If all elements are present but not in order, we can either remove or insert
            insertCost = d;
        }
        
        // Consider the case where removing all elements and inserting a single element might be cheaper
        long long removeAllAndInsertOne = (long long)n * c + d;
        
        return min({removeCost + insertCost, removeAllAndInsertOne});
    }
};


#endif