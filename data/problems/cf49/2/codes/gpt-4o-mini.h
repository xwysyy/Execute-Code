#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int changesA = 0, changesB = 0;
        
        // Check if n is odd, we will need to ignore the last character (which simulates a deletion)
        if (n % 2 != 0) {
            n--; // Simulating a deletion
        }

        // Iterate over the string
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // Even index
                if (s[i] != 'A') changesA++; // Expect A for pattern A
                if (s[i] != 'B') changesB++; // Expect B for pattern B
            } else { // Odd index
                if (s[i] != 'B') changesA++; // Expect B for pattern A
                if (s[i] != 'A') changesB++; // Expect A for pattern B
            }
        }

        // The minimum operations needed to make the string alternating 
        return min(changesA, changesB);
    }
};


#endif