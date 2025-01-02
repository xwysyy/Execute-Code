#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 1) return 1; // If the string length is 1, we need to delete the character.
        
        // Counters for the characters at even and odd positions
        vector<int> even(26, 0), odd(26, 0);
        
        // Count the frequency of each character at even and odd positions
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) even[s[i] - 'a']++;
            else odd[s[i] - 'a']++;
        }
        
        // Find the most frequent characters in even and odd positions
        int maxEven = 0, maxOdd = 0;
        char bestEven, bestOdd;
        for (int i = 0; i < 26; ++i) {
            if (even[i] > maxEven) {
                maxEven = even[i];
                bestEven = 'a' + i;
            }
            if (odd[i] > maxOdd) {
                maxOdd = odd[i];
                bestOdd = 'a' + i;
            }
        }
        
        // If the most frequent characters are different, no need to replace
        if (bestEven != bestOdd) return n - maxEven - maxOdd;
        
        // If the most frequent characters are the same, we need to consider the second best
        int secondMaxEven = 0, secondMaxOdd = 0;
        for (int i = 0; i < 26; ++i) {
            if (i != bestEven - 'a') secondMaxEven = max(secondMaxEven, even[i]);
            if (i != bestOdd - 'a') secondMaxOdd = max(secondMaxOdd, odd[i]);
        }
        
        // Calculate the minimum operations required
        int case1 = n - maxEven - secondMaxOdd; // Replace in odd positions
        int case2 = n - secondMaxEven - maxOdd; // Replace in even positions
        int case3 = n - 1; // Delete one character
        
        return min({case1, case2, case3});
    }
};

#endif