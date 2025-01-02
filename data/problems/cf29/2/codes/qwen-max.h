#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0, len = 0;
            for (int j = i; j < n; ++j) {
                if (j > i && h[j - 1] % h[j] != 0) break;
                sum += a[j];
                if (sum > k) break;
                len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};


#endif