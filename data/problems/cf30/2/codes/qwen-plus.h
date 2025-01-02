#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n, -1);
        int trailingZeros = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                trailingZeros++;
            } else {
                break;
            }
        }
        
        int onesCount = count(s.begin(), s.end(), '1');
        if (onesCount == 0) {
            for (int i = 0; i < n; ++i) {
                if (trailingZeros >= i + 1) {
                    result[i] = 0;
                }
            }
            return result;
        }

        for (int i = 0; i < n; ++i) {
            if (trailingZeros >= i) {
                result[i] = i - trailingZeros;
            } else {
                int neededSwaps = i - trailingZeros;
                int zeroCount = count(s.begin(), s.end() - i, '0');
                if (zeroCount >= neededSwaps) {
                    result[i] = neededSwaps;
                }
            }
        }

        // Adjust the result to ensure non-negative swaps and correct logic
        for (int i = 0; i < n; ++i) {
            if (result[i] != -1 && result[i] < 0) {
                result[i] = -1;
            }
        }

        return result;
    }
};


#endif