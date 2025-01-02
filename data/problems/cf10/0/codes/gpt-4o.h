#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        int max_time = 0;  // Variable to store the maximum time needed.
        int last_g_pos = -1;  // Track the last seen position of 'g' in the cycle.
        
        // Traverse the string to prepare the position of 'g' from the end.
        for (int i = 2 * n - 1; i >= 0; --i) {
            int index = i % n; // To manage cyclic nature
            if (s[index] == 'g') {
                last_g_pos = i;  // Update the last seen green position
            } else if (s[index] == c) {
                // If the current character is the starting character 'c',
                // calculate time to next 'g'.
                if (last_g_pos != -1) { // Ensure there's a g ahead
                    max_time = std::max(max_time, last_g_pos - i);
                }
            }
        }
        
        return max_time;
    }
};


#endif