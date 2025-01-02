#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.length();
        int maxLength = 0;

        // Check for all possible even lengths
        for (int length = 2; length <= n; length += 2) {
            for (int start = 0; start <= n - length; ++start) {
                int mid = start + length / 2;
                string firstHalf = s.substr(start, mid - start);
                string secondHalf = s.substr(mid, length / 2);

                // Count the number of question marks in both halves
                int questionMarks = 0;
                for (char ch : firstHalf) if (ch == '?') questionMarks++;
                for (char ch : secondHalf) if (ch == '?') questionMarks++;

                // Count mismatches between the two halves
                int mismatches = 0;
                for (int i = 0; i < length / 2; ++i) {
                    char a = firstHalf[i], b = secondHalf[i];
                    if (a != b && a != '?' && b != '?') {
                        mismatches++;
                    }
                }

                // If mismatches can be covered by question marks, we can form a tandem repeat
                if (mismatches <= questionMarks) {
                    maxLength = max(maxLength, length);
                }
            }
        }

        return maxLength;
    }
};


#endif