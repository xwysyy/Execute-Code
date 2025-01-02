#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {   
        vector<int> result(n);
        int current_max = a[0];
        int current_count = 1; // Start with the first element
        
        result[0] = current_count; // Cost for the first element
        
        for (int i = 1; i < n; ++i) {
            if (a[i] == current_max) {
                current_count++; // Increment count for the current_max
            } else {
                current_max = a[i]; // Update to new max
                current_count = 1;   // Reset count
            }
            result[i] = current_count; // Cost for the current subsequence
        }
        
        return result;
    }
};


#endif