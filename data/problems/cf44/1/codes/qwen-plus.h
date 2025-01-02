#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) { 
        int maxWins = 0;
        int currentSum = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            currentSum += a[end];

            while (start <= end && currentSum > r) {
                currentSum -= a[start];
                start++;
            }

            if (currentSum >= l && currentSum <= r) {
                maxWins++;
                currentSum = 0;
                start = end + 1;
            }
        }

        return maxWins;
    }
};


#endif