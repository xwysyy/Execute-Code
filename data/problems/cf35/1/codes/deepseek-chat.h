#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int totalSum = 0;
        for (int i = 1; i <= n; ++i) {
            int num = i;
            int sumDigits = 0;
            while (num > 0) {
                sumDigits += num % 10;
                num /= 10;
            }
            totalSum += sumDigits;
        }
        return totalSum;
    }
};


#endif