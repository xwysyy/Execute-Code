#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort the array a in ascending order
        sort(a.begin(), a.end());
        // Sort the array b in descending order
        sort(b.rbegin(), b.rend());
        
        long long maxDifference = 0;
        // Calculate the total difference by pairing a[i] with b[i]
        for(int i = 0; i < n; ++i) {
            maxDifference += abs(a[i] - b[i]);
        }
        
        return maxDifference;
    }
};


#endif