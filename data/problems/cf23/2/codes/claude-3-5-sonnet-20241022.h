#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int maxLen = 0;
        int currentLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }
        
        return maxLen;
    }
};


#endif