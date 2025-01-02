#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        // First, sort the array to make it easier to find duplicates and missing elements
        sort(a.begin(), a.end());
        
        // Use a set to keep track of unique elements
        unordered_set<int> uniqueElements;
        for (int num : a) {
            uniqueElements.insert(num);
        }
        
        // Find the maximum element in the array
        int maxElement = a.empty() ? 0 : a.back();
        
        // The target length of the permutation is the maximum between the number of unique elements and 1
        int targetLength = max(1, (int)uniqueElements.size());
        
        // Calculate the cost of removing duplicates
        long long removeCost = (a.size() - uniqueElements.size()) * c;
        
        // Calculate the cost of inserting missing elements
        long long insertCost = 0;
        for (int i = 1; i <= targetLength; ++i) {
            if (uniqueElements.find(i) == uniqueElements.end()) {
                insertCost += d;
            }
        }
        
        // Calculate the cost of removing elements that are greater than targetLength
        long long removeExtraCost = 0;
        for (int num : a) {
            if (num > targetLength) {
                removeExtraCost += c;
            }
        }
        
        // The total cost is the sum of removeCost, insertCost, and removeExtraCost
        long long totalCost = removeCost + insertCost + removeExtraCost;
        
        return totalCost;
    }
};


#endif