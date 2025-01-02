#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int maxBlankLength = 0;
        int currentBlankLength = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                currentBlankLength++;
            } else {
                if (currentBlankLength > maxBlankLength) {
                    maxBlankLength = currentBlankLength;
                }
                currentBlankLength = 0;
            }
        }
        
        // Final check at the end of the array
        if (currentBlankLength > maxBlankLength) {
            maxBlankLength = currentBlankLength;
        }
        
        return maxBlankLength;
    }
};


#endif