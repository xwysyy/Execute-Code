#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {   
        long long sum = 0;
        bool hasZero = false;
        int minPositive = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                hasZero = true;
            } else if (a[i] > 0) {
                sum += a[i];
                minPositive = min(minPositive, a[i]);
            } else {
                sum += -a[i];
                minPositive = min(minPositive, -a[i]);
            }
        }
        
        if (hasZero || n % 2 == 0) {
            return sum;
        } else {
            return sum - 2 * minPositive;
        }
    }
};

#endif