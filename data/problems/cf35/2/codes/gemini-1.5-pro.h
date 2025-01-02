#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n) {   
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            int digit_sum = 0;
            while (num > 0) {
                digit_sum += num % 10;
                num /= 10;
            }
            sum += digit_sum;
        }
        return sum;
    }
};


#endif