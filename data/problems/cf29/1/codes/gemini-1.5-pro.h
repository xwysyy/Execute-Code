#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool valid = true;
                int currentSum = 0;
                for (int l = i; l <= j; ++l) {
                    currentSum += a[l];
                }
                if (currentSum > k) {
                    continue;
                }
                for (int l = i; l < j; ++l) {
                    if (h[l] % h[l + 1] != 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};


#endif