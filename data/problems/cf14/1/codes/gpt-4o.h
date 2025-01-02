#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, std::vector<int> &a) {
        long long maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            maxSum += std::abs(a[i]);
        }
        
        return maxSum;
    }
};


#endif