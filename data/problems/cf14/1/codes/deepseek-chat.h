#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long sum = 0;
        int count_neg = 0;
        int min_abs = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                count_neg++;
                a[i] = -a[i];
            }
            sum += a[i];
            if (a[i] < min_abs) {
                min_abs = a[i];
            }
        }

        // If the count of negative numbers is odd, subtract twice the smallest absolute value
        if (count_neg % 2 != 0) {
            sum -= 2 * min_abs;
        }

        return sum;
    }
};


#endif