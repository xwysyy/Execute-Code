#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
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
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                }
            } else {
                currentLen = 0;
            }
        }
        
        return maxLen;
    }
};


#endif