#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        // First, sort the array to make it easier to find duplicates and missing elements
        sort(a.begin(), a.end());
        
        // Use a set to find unique elements
        unordered_set<int> uniqueElements;
        for (int num : a) {
            uniqueElements.insert(num);
        }
        
        // Now, we need to find the minimal cost to make the array a permutation
        // We can consider the cost of removing duplicates and inserting missing elements
        
        // First, calculate the cost of removing all elements and then inserting a permutation
        // The cost would be n * c + d * (1) since we can insert any single element
        long long minCost = (long long)n * c + d;
        
        // Now, consider the case where we keep some elements and form a permutation
        // We need to find the largest possible subset of the array that can form a permutation
        // and calculate the cost of removing the rest and inserting the missing elements
        
        // To find the largest possible subset that can form a permutation, we need to find
        // the largest k such that the first k elements of the sorted array are a permutation of [1, k]
        
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == k + 1) {
                k++;
            }
        }
        
        // Now, the cost would be (n - k) * c + (k - uniqueElements.size()) * d
        // Because we need to remove (n - k) elements and insert (k - uniqueElements.size()) elements
        long long cost = (long long)(n - k) * c + (long long)(k - uniqueElements.size()) * d;
        
        // Update the minimum cost
        minCost = min(minCost, cost);
        
        return minCost;
    }
};


#endif