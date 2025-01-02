#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {   
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long maxDiff = 0;
        int i = 0, j = m - 1;
        
        for (int k = 0; k < n; ++k) {
            if (a[k] > b[j]) {
                maxDiff += a[k] - b[j--];
            } else if (a[k] < b[i]) {
                maxDiff += b[i++] - a[k];
            } else {
                // If a[k] is between b[i] and b[j], we need to decide which one to use
                // We choose the one that maximizes the difference
                if (b[j] - a[k] > a[k] - b[i]) {
                    maxDiff += b[j--] - a[k];
                } else {
                    maxDiff += b[i++] - a[k];
                }
            }
        }
        
        return maxDiff;
    }
};

#endif