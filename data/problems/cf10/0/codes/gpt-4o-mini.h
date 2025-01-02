#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        // Find starting point based on the current color 'c'
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                start = i;
                break;
            }
        }

        // Iterate to find the next 'g'
        for (int i = start; i < start + n; i++) {
            if (s[i % n] == 'g') {
                return (i - start + 1); // Return seconds from current position
            }
        }

        return n; // Fallback (although problem guarantees a solution exists)
    }
};


#endif