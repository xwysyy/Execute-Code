#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n <= 1) return 0; // A string of length 0 or 1 is already alternating

        // If the string length is odd, we must delete one character to make it even
        if (n % 2 != 0) {
            return 1 + solve(n-1, s.substr(0, n-1));
        }

        // Count occurrences of each character in even and odd positions
        int freqEven[26] = {0}, freqOdd[26] = {0};
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) freqEven[s[i] - 'a']++;
            else freqOdd[s[i] - 'a']++;
        }

        int maxEven = 0, maxOdd = 0, maxEvenChar = -1, maxOddChar = -1;

        // Find the most frequent characters in even and odd positions
        for (int i = 0; i < 26; ++i) {
            if (freqEven[i] > maxEven) {
                maxEven = freqEven[i];
                maxEvenChar = i;
            }
            if (freqOdd[i] > maxOdd) {
                maxOdd = freqOdd[i];
                maxOddChar = i;
            }
        }

        // If the most frequent characters are different, we can use them directly
        if (maxEvenChar != maxOddChar) {
            return n - maxEven - maxOdd;
        }

        // If they are the same, we need to find the second best choice for either even or odd positions
        int secondMaxEven = 0, secondMaxOdd = 0;
        for (int i = 0; i < 26; ++i) {
            if (i != maxEvenChar && freqEven[i] > secondMaxEven) {
                secondMaxEven = freqEven[i];
            }
            if (i != maxOddChar && freqOdd[i] > secondMaxOdd) {
                secondMaxOdd = freqOdd[i];
            }
        }

        // Return the minimum operations required by considering both cases
        return n - max(maxEven + secondMaxOdd, maxOdd + secondMaxEven);
    }
};


#endif