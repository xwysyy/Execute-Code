#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n <= 1) return n; // If the string is empty or has only one character, it's impossible to make it alternating
        
        // If the string length is already even and all even positions are the same and all odd positions are the same, no operations are needed
        if (n % 2 == 0) {
            bool evenSame = true, oddSame = true;
            char evenChar = s[0], oddChar = s[1];
            for (int i = 0; i < n; i += 2) {
                if (s[i] != evenChar) evenSame = false;
                if (i + 1 < n && s[i + 1] != oddChar) oddSame = false;
            }
            if (evenSame && oddSame && evenChar != oddChar) return 0;
        }

        // Count occurrences of each character in even and odd positions
        vector<int> evenCount(26, 0), oddCount(26, 0);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evenCount[s[i] - 'a']++;
            else oddCount[s[i] - 'a']++;
        }

        int maxEven = 0, maxOdd = 0, secondMaxEven = 0, secondMaxOdd = 0;
        for (int i = 0; i < 26; i++) {
            if (evenCount[i] > evenCount[maxEven]) {
                secondMaxEven = maxEven;
                maxEven = i;
            } else if (evenCount[i] > evenCount[secondMaxEven]) {
                secondMaxEven = i;
            }

            if (oddCount[i] > oddCount[maxOdd]) {
                secondMaxOdd = maxOdd;
                maxOdd = i;
            } else if (oddCount[i] > oddCount[secondMaxOdd]) {
                secondMaxOdd = i;
            }
        }

        // Calculate minimum operations needed
        if (maxEven != maxOdd) {
            return n / 2 - evenCount[maxEven] + n / 2 - oddCount[maxOdd];
        } else {
            return min(n / 2 - evenCount[maxEven] + n / 2 - oddCount[secondMaxOdd],
                       n / 2 - evenCount[secondMaxEven] + n / 2 - oddCount[maxOdd]);
        }
    }
};


#endif