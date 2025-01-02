#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, std::vector<int> &a) {   
        // Step 1: Sort the array
        std::sort(a.begin(), a.end());
        
        // Step 2: Alice removes up to `k` smallest non-negative elements
        // Remove only non-positive starting elements if beneficial
        int i = 0;
        while (i < n && k > 0 && a[i] <= 0) {
            a[i] = 0;  // Set to zero, effectively removing it
            ++i;
            --k;
        }
        
        // Optional removal of small positive elements if k is still left
        while (i < n && k > 0 && a[i] < a[n-1]) {
            a[i] = 0;  // Set to zero
            ++i;
            --k;
        }
        
        // Step 3: Bob negates up to `x` smallest elements
        std::sort(a.begin(), a.end());  // Re-sort after removal operation
        i = 0;
        while (i < n && x > 0 && a[i] < 0) {
            a[i] = -a[i];
            ++i;
            --x;
        }
        
        // Extra negation if required and possible
        std::sort(a.begin(), a.end());
        if (x % 2 == 1) {
            // If any negations left (odd), negate the smallest positive to minimize sum
            a[0] = -a[0];
        }
        
        // Calculate and return the resulting sum
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        return sum;
    }
};


#endif