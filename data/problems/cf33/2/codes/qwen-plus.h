#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        // Sort the array to facilitate optimal removal and flipping
        sort(a.begin(), a.end());
        
        // Remove the smallest k elements to maximize the sum
        for (int i = 0; i < k && i < n; ++i) {
            a[i] = 0;
        }
        
        // Count negative numbers and find the smallest absolute value in the array
        int negCount = 0;
        int minAbsValue = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) {
                negCount++;
            }
            minAbsValue = min(minAbsValue, abs(a[i]));
        }
        
        // Flip at most x negative numbers to positive
        for (int i = 0; i < n && x > 0; ++i) {
            if (a[i] < 0) {
                a[i] = -a[i];
                x--;
            }
        }
        
        // If there are flips left and the number of negative numbers is odd,
        // flip the smallest absolute value element to minimize the impact
        if (x > 0 && negCount % 2 != 0) {
            for (int i = 0; i < n && x > 0; ++i) {
                if (abs(a[i]) == minAbsValue) {
                    a[i] = -a[i];
                    break;
                }
            }
        }
        
        // Calculate the final sum
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        
        return sum;
    }
};


#endif