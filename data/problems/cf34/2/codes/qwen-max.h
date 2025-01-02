#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {   
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long max_diff = 0;
        int i = 0, j = m - 1;
        
        for (int k = 0; k < n; ++k) {
            if (a[k] > b[j]) {
                max_diff += a[k] - b[j--];
            } else if (a[k] < b[i]) {
                max_diff += b[i++] - a[k];
            } else {
                // If a[k] is between b[i] and b[j], we need to decide which one to use
                if (b[j] - a[k] > a[k] - b[i]) {
                    max_diff += b[j--] - a[k];
                } else {
                    max_diff += a[k] - b[i++];
                }
            }
        }
        
        return max_diff;
    }
};

#endif