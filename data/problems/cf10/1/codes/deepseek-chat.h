#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        if (c == 'g') {
            return 0;
        }
        
        int maxWait = 0;
        int currentWait = 0;
        bool foundCurrent = false;
        
        for (int i = 0; i < 2 * n; ++i) {
            char currentColor = s[i % n];
            
            if (currentColor == c && !foundCurrent) {
                foundCurrent = true;
                currentWait = 0;
            }
            
            if (foundCurrent) {
                currentWait++;
                if (currentColor == 'g') {
                    maxWait = max(maxWait, currentWait);
                    foundCurrent = false;
                }
            }
        }
        
        return maxWait;
    }
};


#endif