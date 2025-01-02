#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long sum = 0;
        int countNeg = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                countNeg++;
                a[i] = -a[i];
            }
            sum += a[i];
            if (a[i] < minAbs) {
                minAbs = a[i];
            }
        }

        // If the count of negative numbers is odd, subtract twice the smallest absolute value
        if (countNeg % 2 != 0) {
            sum -= 2 * minAbs;
        }

        return sum;
    }
};


#endif