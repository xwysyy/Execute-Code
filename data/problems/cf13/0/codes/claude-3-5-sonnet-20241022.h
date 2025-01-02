#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Calculate current inversions
        long long curr_inv = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) curr_inv++;
            }
        }
        
        // Try flipping each element and find maximum inversions
        long long max_inv = curr_inv;
        
        for(int i = 0; i < n; i++) {
            // Count how inversions change when we flip a[i]
            long long change = 0;
            
            // If we flip 1 to 0
            if(a[i] == 1) {
                // We lose inversions with previous 0s
                for(int j = 0; j < i; j++) {
                    if(a[j] == 0) change--;
                }
                // We gain inversions with following 1s
                for(int j = i + 1; j < n; j++) {
                    if(a[j] == 1) change++;
                }
            }
            // If we flip 0 to 1
            else {
                // We gain inversions with previous 0s
                for(int j = 0; j < i; j++) {
                    if(a[j] == 0) change++;
                }
                // We lose inversions with following 1s
                for(int j = i + 1; j < n; j++) {
                    if(a[j] == 1) change--;
                }
            }
            
            max_inv = max(max_inv, curr_inv + change);
        }
        
        return max_inv;
    }
};


#endif