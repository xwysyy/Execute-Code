#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int totalSum = 0;
        
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num > 0) {
                totalSum += num % 10;  // Add the last digit
                num /= 10;             // Remove the last digit
            }
        }
        
        return totalSum;
    }
};


#endif