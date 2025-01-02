#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        long long cost = 0;
        unordered_set<int> unique_elements;
        int max_element = 0;
        
        for (int i = 0; i < n; i++) {
            if (unique_elements.count(a[i]) == 0) {
                unique_elements.insert(a[i]);
                max_element = max(max_element, a[i]);
            } else {
                cost += c; // Remove the duplicate element
            }
        }
        
        int required_length = max_element;
        int current_length = unique_elements.size();
        
        if (current_length >= required_length) {
            // We have enough unique elements to form a permutation
            return cost;
        } else {
            // We need to add more elements to form a permutation
            int elements_to_add = required_length - current_length;
            cost += 1LL * elements_to_add * d;
        }
        
        return cost;
    }
};

#endif