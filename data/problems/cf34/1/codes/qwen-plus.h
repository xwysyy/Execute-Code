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
        
        // Two pointers to traverse from the start and end of b
        int left = 0;
        int right = m - 1;
        long long maxDifference = 0;
        
        // Try to maximize the difference by pairing largest and smallest elements in b with elements in a
        for (int i = 0; i < n; ++i) {
            if (abs(a[i] - b[left]) > abs(a[i] - b[right])) {
                maxDifference += abs(a[i] - b[left++]);
            } else {
                maxDifference += abs(a[i] - b[right--]);
            }
        }
        
        return maxDifference;
    }
};


#endif