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

        long long total_difference = 0;
        
        // Calculate the maximum difference
        for (int i = 0; i < n; ++i) {
            // Take the maximum of the two possible absolute differences
            total_difference += max(abs(a[i] - b[0]), abs(a[i] - b[m - 1]));
        }

        return total_difference;
    }
};


#endif