#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {   
        vector<long long> result(n, -1);
        int zeroCount = 0;
        
        // Count trailing zeros and check for feasibility
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zeroCount++;
            } else {
                break;
            }
        }

        // If the entire string is zeros, all operations are feasible with 0 swaps
        if (zeroCount == n) {
            for (int i = 0; i < n; ++i) {
                result[i] = 0;
            }
            return result;
        }

        // Calculate minimum swaps needed for each i
        int oneCount = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                oneCount++;
            } else {
                zeroCount++;
            }
            if (oneCount > 0) {
                result[i] = oneCount - 1 + (n - 1 - i - zeroCount);
            }
        }

        // Adjust the result to be valid for each i
        int currentZeros = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                currentZeros++;
            }
            if (currentZeros >= i + 1) {
                result[i] = 0;
            } else {
                result[i] = (i + 1 - currentZeros);
            }
        }

        // Final adjustment for correct results
        for (int i = 0; i < n; ++i) {
            if (result[i] != -1 && zeroCount >= i) {
                result[i] = i - zeroCount;
            } else {
                result[i] = -1;
            }
        }

        return result;
    }
};


#endif