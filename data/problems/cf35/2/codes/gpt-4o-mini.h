#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int totalSum = 0;
        for (int i = 1; i <= n; ++i) {
            int num = i;
            while (num > 0) {
                totalSum += num % 10;
                num /= 10;
            }
        }
        return totalSum;
    }
};


#endif