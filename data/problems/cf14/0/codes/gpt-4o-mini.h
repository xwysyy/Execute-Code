#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {   
        long long maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum += abs(a[i]);
        }
        return maxSum;
    }
};


#endif