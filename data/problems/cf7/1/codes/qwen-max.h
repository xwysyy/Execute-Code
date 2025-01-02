#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {   
        int saved = 0;
        int lidPos = -1;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                lidPos = i;
            } else if (lidPos != -1 && s[lidPos] == '1') {
                saved += a[i];
                s[lidPos] = '0';
                lidPos = -1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                saved += a[i];
            }
        }
        
        return saved;
    }
};

#endif