#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        if (n < 2) return 0; // Sanity check; should not happen due to constraints
        
        long long max1 = -1e9 - 1, max2 = -1e9 - 1;
        long long min1 = 1e9 + 1, min2 = 1e9 + 1;

        // Iterate through the array to find the two largest and two smallest numbers
        for (int i = 0; i < n; i++) {
            if (a[i] > max1) {
                max2 = max1; // update second max
                max1 = a[i]; // update first max
            } else if (a[i] > max2) {
                max2 = a[i]; // update second max
            }
            
            if (a[i] < min1) {
                min2 = min1; // update second min
                min1 = a[i]; // update first min
            } else if (a[i] < min2) {
                min2 = a[i]; // update second min
            }
        }
        
        // Calculate the maximum product of either the two largest or two smallest numbers
        long long product1 = max1 * max2; // product of the two largest
        long long product2 = min1 * min2; // product of the two smallest
        
        return max(product1, product2);
    }
};


#endif