#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {   
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int temp = i;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
        }
        return sum;
    }
};


#endif