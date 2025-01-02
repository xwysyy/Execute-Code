#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n < 2) return 0;
        
        // Check if the string is already alternating
        bool isAlternating = true;
        char evenChar = s[0];
        char oddChar = s[1];
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0 && s[i] != evenChar) {
                isAlternating = false;
                break;
            }
            if (i % 2 == 1 && s[i] != oddChar) {
                isAlternating = false;
                break;
            }
        }
        if (isAlternating && n % 2 == 0) return 0;
        
        // Try deleting one character
        int minOps = INT_MAX;
        for (int i = 0; i < n; i++) {
            string temp = s;
            temp.erase(i, 1);
            int m = temp.length();
            if (m % 2 != 0) continue;
            char evenCharTemp = temp[0];
            char oddCharTemp = temp[1];
            bool valid = true;
            for (int j = 2; j < m; j++) {
                if (j % 2 == 0 && temp[j] != evenCharTemp) {
                    valid = false;
                    break;
                }
                if (j % 2 == 1 && temp[j] != oddCharTemp) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                minOps = min(minOps, 1);
                break;
            }
        }
        
        // Try replacing characters
        int replaceOps = 0;
        evenChar = s[0];
        oddChar = s[1];
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0 && s[i] != evenChar) {
                replaceOps++;
            }
            if (i % 2 == 1 && s[i] != oddChar) {
                replaceOps++;
            }
        }
        if (n % 2 == 0) {
            minOps = min(minOps, replaceOps);
        }
        
        return minOps;
    }
};


#endif