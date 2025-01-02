#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n, 0);
        for (int i = 1; i <= n; ++i) {
            int zeroPos = -1;
            for (int j = n - i; j >= 0; --j) {
                if (s[j] == '0') {
                    zeroPos = j;
                    break;
                }
            }
            if (zeroPos == -1) {
                result[i - 1] = -1;
            } else {
                result[i - 1] = (n - i - zeroPos) + (i - 1);
            }
        }
        return result;
    }
};

#endif