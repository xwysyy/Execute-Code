#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
        }
        return sum;
    }
};

#endif