#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> freq(n + 1, 0);
        
        // Count frequency of each element
        for(int i = 0; i < n; i++) {
            freq[a[i]]++;
        }
        
        // Find the minimum value that appears at least 3 times
        for(int i = 1; i <= n; i++) {
            if(freq[i] >= 3) {
                return i;
            }
        }
        
        return -1;
    }
};


#endif