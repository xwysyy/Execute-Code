#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        // Sort the array to facilitate removals and sign flips
        sort(a.begin(), a.end());

        // Step 1: Alice removes up to k smallest elements
        for (int i = 0; i < k && i < n; i++) {
            a[i] = 0; // Pretend the removed elements are 0 (since they are removed)
        }

        // Step 2: Bob flips up to x largest elements
        // To do this, we need to consider the non-zero elements after removal
        int flipCount = 0;

        // Reverse iterate to find the largest elements for Bob to flip
        for (int i = n - 1; i >= 0 && flipCount < x; i--) {
            if (a[i] > 0) {
                a[i] = -a[i]; // Flip the sign
                flipCount++;
            }
        }

        // Step 3: Calculate the sum of the modified array
        int totalSum = 0;
        for (int num : a) {
            totalSum += num;
        }

        return totalSum;
    }
};


#endif