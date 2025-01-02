#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, std::vector<int> &a) {
        std::sort(a.begin(), a.end());
        std::unordered_set<int> uniqueElements;
        for (int num : a) {
            uniqueElements.insert(num);
        }
        
        long long minCost = LLONG_MAX;
        int maxPossibleLength = uniqueElements.size() + n; // Upper bound for the length of the permutation
        
        for (int len = 1; len <= maxPossibleLength; ++len) {
            long long cost = 0;
            std::vector<int> targetPermutation;
            for (int i = 1; i <= len; ++i) {
                targetPermutation.push_back(i);
            }
            
            int i = 0, j = 0;
            while (i < n && j < len) {
                if (a[i] == targetPermutation[j]) {
                    i++;
                    j++;
                } else if (a[i] < targetPermutation[j]) {
                    cost += c; // Remove a[i]
                    i++;
                } else {
                    cost += d; // Insert targetPermutation[j]
                    j++;
                }
            }
            
            while (i < n) {
                cost += c; // Remove remaining elements
                i++;
            }
            
            while (j < len) {
                cost += d; // Insert remaining elements
                j++;
            }
            
            if (cost < minCost) {
                minCost = cost;
            }
        }
        
        return minCost;
    }
};


#endif