#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int timarApplications = 0;
        int i = 0;
        
        // Iterate over the binary string
        while (i < n) {
            // If there's a complete weak segment of length m starting at i
            if (s[i] == '0') {
                // Check if this segment could be weak
                int zeroCount = 0;
                while (i + zeroCount < n && s[i + zeroCount] == '0' && zeroCount < m) {
                    zeroCount++;
                }

                if (zeroCount == m) {
                    // We need to apply Timar here
                    timarApplications++;
                    // Strengthen the segment of length k starting at i
                    // Move forward by k (since we have strengthened k spots)
                    i += k;
                } else {
                    // Move forward by max(1, zeroCount) (because if zeroCount > m, we're no longer in danger of a weak segment)
                    i += std::max(1, zeroCount);
                }
            } else {
                // Move one step, this place is already strong
                i++;
            }
        }
        
        return timarApplications;
    }
};


#endif