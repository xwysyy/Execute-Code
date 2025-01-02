#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int result = 0;
        int lastStrengthened = -1;

        for (int i = 0; i <= n - m; ) {
            if (s[i] == '0') {
                // Find the next segment to strengthen
                int strengthenStart = max(lastStrengthened + 1, i);
                if (strengthenStart + k - 1 < i + m) {
                    // If there's no valid segment to strengthen, return -1
                    return -1;
                }
                // Strengthen the segment [strengthenStart, strengthenStart + k - 1]
                lastStrengthened = strengthenStart + k - 1;
                result++;
                i += m;
            } else {
                i++;
            }
        }

        return result;
    }
};


#endif