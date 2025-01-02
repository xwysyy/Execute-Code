#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        int maxLength = 0;
        int currentLength = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }

        return maxLength;
    }
};

#endif