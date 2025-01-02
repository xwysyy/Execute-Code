#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Sort array a in ascending order
        sort(a.begin(), a.end());
        // Sort array b in descending order
        sort(b.begin(), b.end(), greater<int>());
        
        long long maxDiff = 0;
        for (int i = 0; i < n; i++) {
            // Calculate the absolute difference between the smallest a[i] and largest b[i]
            maxDiff += abs(a[i] - b[i]);
        }
        
        return maxDiff;
    }
};


#endif