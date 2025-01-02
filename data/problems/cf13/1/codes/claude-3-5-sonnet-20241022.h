#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Count current inversions
        long long curr_inv = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) curr_inv++;
            }
        }
        
        // Try flipping each element and find max inversions
        long long max_inv = curr_inv;
        
        for(int i = 0; i < n; i++) {
            // Calculate change in inversions if we flip a[i]
            long long change = 0;
            
            // Count elements before i
            for(int j = 0; j < i; j++) {
                if(a[i] == 0 && a[j] == 0) change++;     // 0->1 creates new inversion
                if(a[i] == 0 && a[j] == 1) change--;     // 0->1 removes inversion
                if(a[i] == 1 && a[j] == 0) change--;     // 1->0 removes inversion
                if(a[i] == 1 && a[j] == 1) change++;     // 1->0 creates inversion
            }
            
            // Count elements after i
            for(int j = i + 1; j < n; j++) {
                if(a[i] == 0 && a[j] == 0) change--;     // 0->1 removes inversion
                if(a[i] == 0 && a[j] == 1) change++;     // 0->1 creates inversion
                if(a[i] == 1 && a[j] == 0) change++;     // 1->0 creates inversion
                if(a[i] == 1 && a[j] == 1) change--;     // 1->0 removes inversion
            }
            
            max_inv = max(max_inv, curr_inv + change);
        }
        
        return max_inv;
    }
};


#endif