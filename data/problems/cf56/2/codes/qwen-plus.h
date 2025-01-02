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
            if (s[i] == '0' && i > lastStrengthenedPos + k - 1) {
                bool canStrengthen = false;
                for (int j = max(i, lastStrengthenedPos + k); j <= min(i + k - 1, n - m); ++j) {
                    if (s[j] == '0') {
                        lastStrengthenedPos = j;
                        result++;
                        canStrengthen = true;
                        break;
                    }
                }
                if (!canStrengthen) {
                    return -1; // Impossible to strengthen in a valid way
                }
            }
        }

        // Check the remaining part of the string
        int remainingWeakSpots = 0;
        for (int i = n - m + 1; i < n; ++i) {
            if (s[i] == '0') remainingWeakSpots++;
        }
        if (remainingWeakSpots == m) return -1;

        return result;
    }
};


#endif