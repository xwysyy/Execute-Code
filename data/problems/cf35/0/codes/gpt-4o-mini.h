#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int total_sum = 0;
        
        for (int i = 1; i <= n; ++i) {
            int num = i;
            while (num > 0) {
                total_sum += num % 10;
                num /= 10;
            }
        }
        
        return total_sum;
    }
};


#endif