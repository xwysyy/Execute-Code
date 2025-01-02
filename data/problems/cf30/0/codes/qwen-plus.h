#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {   
        vector<long long> result(n, -1);
        int zeroCount = 0;
        
        // Count the number of trailing zeros in the binary string
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zeroCount++;
            } else {
                break;
            }
        }

        // Calculate the minimum swaps needed for each i
        for (int i = 1; i <= n; ++i) {
            if (zeroCount >= i) {
                result[i - 1] = 0;
            } else {
                int swapCount = 0;
                int requiredZeros = i - zeroCount;
                int nonZeroPos = n - zeroCount - 1;

                for (int j = nonZeroPos; j >= 0 && requiredZeros > 0; --j) {
                    if (s[j] == '0') {
                        swapCount += (nonZeroPos - j - requiredZeros + 1);
                        requiredZeros--;
                    }
                }

                if (requiredZeros == 0) {
                    result[i - 1] = swapCount;
                }
            }
        }

        return result;
    }
};


#endif