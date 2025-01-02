#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int num_operations = 0;
        // We will be scanning through the string to find intervals of '0's
        int i = 0;

        while (i < n) {
            // Find the first segment of weak spots (0's)
            if (s[i] == '0') {
                int start = i; // starting index of the weak segment
                // Move until we find the end of the segment of '0's
                while (i < n && s[i] == '0') {
                    i++;
                }
                int length = i - start; // length of the weak segment
                
                // If this segment length is greater than or equal to m,
                // we have to take action to ensure no interval of length m is all weak
                if (length >= m) {
                    // Calculate how many k-length segments we need to cover this length
                    // We need to cover (length - m + 1) positions
                    // Each time we use Timar, we can cover k positions in the segment
                    int needed = (length - m + 1 + k - 1) / k; // ceil division
                    num_operations += needed;
                    
                    // Move the index forward, we can effectively jump
                    // We can think that after using Timar, we won't need to check the first 'm - 1' zeros next
                    i = start + needed * k - m + 1;
                }
            } else {
                i++;
            }
        }

        return num_operations;
    }
};


#endif