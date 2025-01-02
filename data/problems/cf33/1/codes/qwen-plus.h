#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {   
        // Sort the array to facilitate optimal removal and flipping
        sort(a.begin(), a.end());
        
        // Alice removes the smallest k elements to maximize the sum
        for (int i = 0; i < k && i < n; ++i) {
            a.erase(a.begin());
            --n;
        }
        
        // Count negative numbers and find the smallest absolute value in the remaining array
        int negatives = 0;
        int minAbsValue = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) negatives++;
            minAbsValue = min(minAbsValue, abs(a[i]));
        }
        
        // Bob flips up to x elements to minimize the sum
        for (int i = 0; i < n && x > 0; ++i) {
            if (a[i] < 0 && x > 0) {
                a[i] = -a[i];
                --x;
            }
        }
        
        // If there are flips left and the number of flips is odd, flip the smallest absolute value element
        if (x % 2 != 0) {
            for (int i = 0; i < n; ++i) {
                if (abs(a[i]) == minAbsValue) {
                    a[i] = -a[i];
                    break;
                }
            }
        }
        
        // Calculate the final sum
        int sum = accumulate(a.begin(), a.end(), 0);
        return sum;
    }
};


#endif