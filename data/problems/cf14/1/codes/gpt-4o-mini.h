#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {   
        long long max_sum = 0;
        for (int i = 0; i < n; ++i) {
            max_sum += abs(a[i]); // Summing the absolute values of the elements
        }
        return max_sum; // Return the calculated max sum
    }
};


#endif