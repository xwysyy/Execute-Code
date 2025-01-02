#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int solve(int &n) {   
        int totalSum = 0;
        for (int i = 1; i <= n; i++) {
            totalSum += getDigitSum(i);
        }
        return totalSum;
    }
};


#endif