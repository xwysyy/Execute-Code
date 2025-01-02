#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long maxDifference = 0;
        
        // Option 1: Pair a[i] with the largest values in b
        for (int i = 0; i < n; ++i) {
            maxDifference += abs(a[i] - b[m - 1 - i]); // largest in b
        }
        
        // Option 2: Pair a[i] with the smallest values in b
        long long minDifference = 0;
        for (int i = 0; i < n; ++i) {
            minDifference += abs(a[i] - b[i]); // smallest in b
        }

        return max(maxDifference, minDifference);
    }
};


#endif