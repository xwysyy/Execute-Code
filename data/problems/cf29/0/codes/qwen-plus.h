#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {   
        int maxLen = 0;
        for (int start = 0; start < n; ++start) {
            int fruitSum = 0;
            int end = start;
            bool isValid = true;
            while (end < n && fruitSum + a[end] <= k && isValid) {
                if (end > start && h[end - 1] % h[end] != 0) {
                    isValid = false;
                    break;
                }
                fruitSum += a[end];
                if (fruitSum <= k) {
                    maxLen = max(maxLen, end - start + 1);
                }
                ++end;
            }
        }
        return maxLen;
    }
};


#endif