#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {   
        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Initialize pointers and the result variable
        int i = 0, j = 0, k = m - 1;
        long long max_diff = 0;
        
        // Try to maximize the difference by choosing the largest or smallest elements from b
        while (i < n) {
            // Check if the smallest remaining element in b gives a larger difference than the largest
            if (abs(a[i] - b[j]) > abs(a[i] - b[k])) {
                max_diff += abs(a[i] - b[k]);
                k--;
            } else {
                max_diff += abs(a[i] - b[j]);
                j++;
            }
            i++;
        }
        
        return max_diff;
    }
};


#endif