#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 1) return 1; // If the length is 1, we need to delete the character to make it even.
        if (n == 2) return s[0] != s[1]; // If the length is 2, check if the characters are the same.

        // Count the frequency of characters in odd and even positions.
        vector<int> odd(26, 0), even(26, 0);
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) even[s[i] - 'a']++;
            else odd[s[i] - 'a']++;
        }

        // Find the most frequent character in odd and even positions.
        int maxOdd = *max_element(odd.begin(), odd.end());
        int maxEven = *max_element(even.begin(), even.end());

        // Calculate the minimum operations needed.
        int minOps = n - maxOdd - maxEven;

        // Check if deleting one character can reduce the number of operations.
        for (int i = 0; i < n; ++i) {
            int newMaxOdd = maxOdd, newMaxEven = maxEven;
            if (i % 2 == 0) newMaxEven = max(maxEven, *max_element(even.begin(), even.end()) - 1);
            else newMaxOdd = max(maxOdd, *max_element(odd.begin(), odd.end()) - 1);
            minOps = min(minOps, n - 1 - newMaxOdd - newMaxEven);
        }

        return minOps;
    }
};

#endif