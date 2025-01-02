#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {   
        // Sort the array to facilitate optimal removal and flipping
        sort(a.begin(), a.end());
        
        // Alice removes the smallest elements first to maximize the sum
        for (int i = 0; i < k && i < n; ++i) {
            if (a[i] < 0) {
                a.erase(a.begin() + i);
                --i; // Adjust index since we erased an element
                --n; // Decrease the size of the array
            } else {
                break;
            }
        }
        
        // Count negative numbers in the remaining array
        int neg_count = 0;
        for (int num : a) {
            if (num < 0) ++neg_count;
        }
        
        // If there are more negatives than Bob can flip, flip the largest negatives
        if (neg_count > x) {
            sort(a.begin(), a.end()); // Re-sort to ensure smallest abs values are flipped
            for (int i = 0; i < x; ++i) {
                a[i] = -a[i];
            }
        } else {
            // Otherwise, flip all negatives and use remaining flips on smallest absolute values
            for (int i = 0; i < neg_count; ++i) {
                a[i] = -a[i];
            }
            x -= neg_count;
            if (x % 2 == 1 && !a.empty()) {
                // If x is odd, flip the smallest absolute value element
                sort(a.begin(), a.end(), [](int a, int b) { return abs(a) < abs(b); });
                a[0] = -a[0];
            }
        }
        
        // Calculate the final sum
        int sum = accumulate(a.begin(), a.end(), 0);
        return sum;
    }
};


#endif