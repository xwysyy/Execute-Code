#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {   
        int maxLength = 0;
        for (int start = 0; start < n; ++start) {
            int currentFruits = 0;
            int end = start;
            bool isValid = true;
            while (end < n && isValid) {
                if (start != end) {
                    if (h[end - 1] % h[end] != 0) {
                        isValid = false;
                        break;
                    }
                }
                currentFruits += a[end];
                if (currentFruits > k) {
                    isValid = false;
                } else {
                    maxLength = max(maxLength, end - start + 1);
                }
                ++end;
            }
        }
        return maxLength;
    }
};


#endif