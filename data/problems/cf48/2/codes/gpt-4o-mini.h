#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        // Sort the initial array
        sort(a.begin(), a.end());
        
        // Prepare a result vector
        vector<int> results;
        
        // Perform each operation
        for (const auto& op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];
            
            if (type == 1) { // Increment operation
                // Find indices in the range [l, r]
                auto start = lower_bound(a.begin(), a.end(), l);
                auto end = upper_bound(a.begin(), a.end(), r);
                
                // Increment all elements in the range
                for (auto it = start; it != end; ++it) {
                    (*it)++;
                }
            } else { // Decrement operation
                // Find indices in the range [l, r]
                auto start = lower_bound(a.begin(), a.end(), l);
                auto end = upper_bound(a.begin(), a.end(), r);
                
                // Decrement all elements in the range
                for (auto it = start; it != end; ++it) {
                    (*it)--;
                }
            }
            
            // After performing operation, calculate the current maximum
            results.push_back(*a.rbegin()); // The last element is the max after sorting
        }
        
        return results;
    }
};


#endif