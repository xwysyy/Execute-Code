#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {   
        int maxLength = 0;
        for (int start = 0; start < n; ++start) {
            int currentFruitSum = 0;
            int end = start;
            bool isValid = true;
            for (; end < n && isValid; ++end) {
                if (start < end && h[end - 1] % h[end] != 0) {
                    isValid = false;
                    break;
                }
                currentFruitSum += a[end];
                if (currentFruitSum > k) {
                    isValid = false;
                }
                if (isValid) {
                    maxLength = max(maxLength, end - start + 1);
                }
            }
        }
        return maxLength;
    }
};


#endif