#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLen = 0;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (right > 0 && h[right - 1] % h[right] != 0) {
                left = right;
                currentSum = 0;
            }
            currentSum += a[right];
            while (currentSum > k) {
                currentSum -= a[left];
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};


#endif