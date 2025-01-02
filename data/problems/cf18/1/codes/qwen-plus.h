#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        if (n == 0) return d; // If the array is empty, the only option is to insert one element
        
        // Remove duplicates and sort the array
        std::set<int> unique_elements(a.begin(), a.end());
        std::vector<int> sorted_unique(unique_elements.begin(), unique_elements.end());
        
        // Case 1: Forming the largest possible permutation with existing elements
        int m = sorted_unique.size();
        if (m == 0) return d; // If no unique elements, just insert one element
        
        // Find the longest contiguous sequence starting from 1
        int longest_contiguous = 0;
        for (int i = 1; i <= m; ++i) {
            if (std::find(sorted_unique.begin(), sorted_unique.end(), i) != sorted_unique.end()) {
                longest_contiguous++;
            } else {
                break;
            }
        }

        // Cost to remove elements not part of the permutation [1, longest_contiguous]
        long long remove_cost = (long long)(n - longest_contiguous) * c;
        
        // Cost to insert missing elements to complete the permutation [1, longest_contiguous]
        long long insert_cost = (longest_contiguous - m) * d;

        // Total cost for this strategy
        long long cost1 = remove_cost + insert_cost;

        // Case 2: Clear all elements and start fresh by inserting [1, n]
        long long cost2 = (long long)n * c + d;

        // Return the minimum of both strategies
        return std::min(cost1, cost2);
    }
};


#endif