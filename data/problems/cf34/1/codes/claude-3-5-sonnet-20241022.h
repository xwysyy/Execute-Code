#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort array b to help with selecting max/min values
        sort(b.begin(), b.end());
        
        // Create a copy of array a to sort alongside indices
        vector<pair<int, int>> a_pairs(n);
        for(int i = 0; i < n; i++) {
            a_pairs[i] = {a[i], i};
        }
        sort(a_pairs.begin(), a_pairs.end());
        
        // Create result array
        vector<int> result(n);
        
        // For small values in a, use large values from b
        // For large values in a, use small values from b
        int left = 0, right = m-1;
        for(int i = 0; i < n; i++) {
            if(i < n/2) {
                // For smaller half of a, use larger values from b
                result[a_pairs[i].second] = b[right--];
            } else {
                // For larger half of a, use smaller values from b
                result[a_pairs[i].second] = b[left++];
            }
        }
        
        // Calculate total difference
        long long diff = 0;
        for(int i = 0; i < n; i++) {
            diff += abs((long long)a[i] - result[i]);
        }
        
        return diff;
    }
};


#endif