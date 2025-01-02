#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int maxBlank = 0;
        int currentBlank = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                currentBlank++;
                maxBlank = max(maxBlank, currentBlank);
            } else {
                currentBlank = 0;
            }
        }
        
        return maxBlank;
    }
};


#endif