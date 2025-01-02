#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        // Step 1: Sort the array
        sort(a.begin(), a.end());

        // Step 2: Alice removes the smallest k elements
        // Only consider elements from index k to n-1
        int startIdx = k;  // Start from the k-th index
        int endIdx = n - 1; // Last index

        // Step 3: Bob will negate up to x largest elements
        int remainCount = endIdx - startIdx + 1; // Number of remaining elements after Alice's move
        int negationCount = min(x, remainCount); // Bob can negate at most x elements or remaining elements

        // Step 4: Negate the last negationCount elements (largest remaining)
        for (int i = 0; i < negationCount; i++) {
            a[endIdx - i] = -a[endIdx - i];
        }

        // Step 5: Calculate the total sum
        int totalSum = 0;
        for (int i = startIdx; i <= endIdx; i++) {
            totalSum += a[i];
        }

        return totalSum;
    }
};


#endif