#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Initialize the two largest and the two smallest elements
        long long max1 = LLONG_MIN, max2 = LLONG_MIN; // for positive products
        long long min1 = LLONG_MAX, min2 = LLONG_MAX; // for negative products
        
        for (int i = 0; i < n; ++i) {
            // Update the two largest values
            if (a[i] > max1) {
                max2 = max1;
                max1 = a[i];
            } else if (a[i] > max2) {
                max2 = a[i];
            }
            
            // Update the two smallest values
            if (a[i] < min1) {
                min2 = min1;
                min1 = a[i];
            } else if (a[i] < min2) {
                min2 = a[i];
            }
        }
        
        // The maximum beauty can be either from two largest or two smallest products
        long long product1 = max1 * max2; // product of the two largest positives
        long long product2 = min1 * min2; // product of the two smallest (negatives)
        
        return max(product1, product2);
    }
};


#endif