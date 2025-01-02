#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort array a and b
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long maxDifference = 0;

        // Calculate the max difference by pairing max a with min b
        for (int i = 0; i < n; i++) {
            maxDifference += abs(a[i] - b[i]); // a[i] with b[i]
        }

        // Calculate the max difference by pairing min a with max b
        long long alternativeDifference = 0;
        for (int i = 0; i < n; i++) {
            alternativeDifference += abs(a[i] - b[m - 1 - i]); // a[i] with b[m - 1 - i]
        }

        // Return the maximum of both options
        return max(maxDifference, alternativeDifference);
    }
};


#endif