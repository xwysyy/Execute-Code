#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {   
        sort(a.begin(), a.end());
        
        // Alice removes the smallest k elements to maximize the sum
        for (int i = 0; i < k && i < n; ++i) {
            if (a[i] >= 0) break;
            a[i] = 0; // Mark as removed
        }
        
        // Bob will try to minimize the sum by flipping the largest x positive elements
        nth_element(a.begin(), a.begin() + n - x, a.end(), greater<int>());
        for (int i = n - x; i < n; ++i) {
            a[i] = -a[i];
        }
        
        // Calculate the final sum
        return accumulate(a.begin(), a.end(), 0);
    }
};

#endif