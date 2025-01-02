#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Initialize the maximum beauty as the smallest possible value
        long long max_beauty = LLONG_MIN;
        
        // Iterate through the array to find the maximum product of adjacent pairs
        for (int i = 0; i < n - 1; ++i) {
            long long product = static_cast<long long>(a[i]) * a[i + 1];
            max_beauty = max(max_beauty, product);
        }
        
        return max_beauty;
    }
};


#endif