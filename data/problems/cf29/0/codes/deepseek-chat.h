#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLen = 0;
        int currentLen = 0;
        int currentSum = 0;
        
        for (int i = 0; i < n; ++i) {
            if (currentLen == 0) {
                currentLen = 1;
                currentSum = a[i];
            } else {
                if (h[i-1] % h[i] == 0) {
                    currentLen++;
                    currentSum += a[i];
                } else {
                    currentLen = 1;
                    currentSum = a[i];
                }
            }
            
            if (currentSum <= k) {
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
                currentSum = 0;
            }
        }
        
        return maxLen;
    }
};


#endif