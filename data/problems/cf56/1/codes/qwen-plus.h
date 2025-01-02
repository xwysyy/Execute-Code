#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int result = 0;
        int lastStrengthenedPos = -1;

        for (int i = 0; i <= n - m; ++i) {
            bool allWeak = true;
            for (int j = i; j < i + m; ++j) {
                if (s[j] == '1') {
                    allWeak = false;
                    break;
                }
            }

            if (allWeak) {
                int strengthenStart = max(i, lastStrengthenedPos + 1);
                if (strengthenStart + k - 1 >= i && strengthenStart + k - 1 < n) {
                    lastStrengthenedPos = strengthenStart + k - 1;
                    result++;
                    for (int l = strengthenStart; l <= min(strengthenStart + k - 1, n - 1); ++l) {
                        s[l] = '1';
                    }
                } else {
                    return -1; // Impossible to strengthen within constraints
                }
            }
        }

        return result;
    }
};


#endif