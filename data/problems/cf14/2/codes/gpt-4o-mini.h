#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long max_sum = 0; // Using long long to handle large sums
        
        for (int i = 0; i < n; i++) {
            max_sum += abs(a[i]); // Add the absolute value of the current element
        }
        
        return max_sum; // Final maximum sum after considering all flips
    }
};


#endif