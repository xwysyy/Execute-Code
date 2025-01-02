#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        vector<int> freq(n + 1, 0);
        
        // Count frequency of each element
        for(int x : a) {
            freq[x]++;
            // If we find an element with frequency 3, return it immediately
            if(freq[x] >= 3) {
                return x;
            }
        }
        
        return -1;
    }
};


#endif