#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n <= 1) return n; // If length is 0 or 1, it's already "alternating" by definition
        
        // If the string length is odd, we must delete one character to make it even
        if (n % 2 != 0) {
            return 1 + solve(n-1, s.substr(0, n-1));
        }
        
        // Frequency of characters at even and odd positions
        int freqEven[26] = {0}, freqOdd[26] = {0};
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) freqEven[s[i] - 'a']++;
            else freqOdd[s[i] - 'a']++;
        }
        
        int maxEven = 0, maxOdd = 0, secondMaxEven = 0, secondMaxOdd = 0;
        for (int i = 0; i < 26; ++i) {
            if (freqEven[i] > freqEven[maxEven]) {
                secondMaxEven = maxEven;
                maxEven = i;
            } else if (freqEven[i] > freqEven[secondMaxEven]) {
                secondMaxEven = i;
            }
            
            if (freqOdd[i] > freqOdd[maxOdd]) {
                secondMaxOdd = maxOdd;
                maxOdd = i;
            } else if (freqOdd[i] > freqOdd[secondMaxOdd]) {
                secondMaxOdd = i;
            }
        }
        
        // Calculate minimum changes needed
        if (maxEven != maxOdd) {
            return n / 2 - freqEven[maxEven] + n / 2 - freqOdd[maxOdd];
        } else {
            return min(n / 2 - freqEven[maxEven] + n / 2 - freqOdd[secondMaxOdd],
                       n / 2 - freqEven[secondMaxEven] + n / 2 - freqOdd[maxOdd]);
        }
    }
};


#endif