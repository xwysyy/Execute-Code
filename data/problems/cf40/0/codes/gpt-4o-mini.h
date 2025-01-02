#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.length();
        int maxLength = 0;

        // Iterate over all possible even lengths
        for (int len = 2; len <= n; len += 2) { // length from 2 to n, step by 2
            for (int start = 0; start <= n - len; ++start) {
                // Define the two halves
                string firstHalf = s.substr(start, len / 2);
                string secondHalf = s.substr(start + len / 2, len / 2);
                int questionMarks = 0;
                int matches = 0;

                // Count characters in both halves
                for (int i = 0; i < len / 2; ++i) {
                    char c1 = firstHalf[i];
                    char c2 = secondHalf[i];

                    if (c1 == '?' || c2 == '?') {
                        questionMarks++;
                    } else if (c1 == c2) {
                        matches++;
                    }
                }

                // Calculate the total matches we could have with replacements
                int totalMatches = matches + (questionMarks / 2);
                if (totalMatches * 2 > len) {
                    maxLength = max(maxLength, len);
                }
            }
        }

        return maxLength;
    }
};


#endif