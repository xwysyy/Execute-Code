#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int max_len = 0;
        int current_len = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                current_len++;
            } else {
                max_len = max(max_len, current_len);
                current_len = 0;
            }
        }
        max_len = max(max_len, current_len);
        return max_len;
    }
};


#endif