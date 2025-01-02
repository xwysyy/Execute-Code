#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.length();
        int maxLength = 0;

        // We will check for every possible even length
        for (int len = 2; len <= n; len += 2) {
            for (int start = 0; start + len <= n; start++) {
                string firstHalf = s.substr(start, len / 2);
                string secondHalf = s.substr(start + len / 2, len / 2);
                int questionMarks = 0;

                // Calculate the mismatches between firstHalf and secondHalf
                for (int i = 0; i < len / 2; i++) {
                    if (firstHalf[i] != secondHalf[i]) {
                        if (firstHalf[i] == '?' || secondHalf[i] == '?') {
                            questionMarks++;
                        } else {
                            // Not matching and not a question mark
                            break;
                        }
                    }
                }

                // If we can use question marks to fill gaps, we consider this as a possible tandem repeat
                if (firstHalf == secondHalf || questionMarks == (len / 2)) {
                    maxLength = max(maxLength, len);
                }
            }
        }
        
        return maxLength;
    }
};


#endif