#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        int time_to_wait = 0;
        // We cycle through the string to find the position of the current color
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                time_to_wait = i; // Set the initial waiting time based on the current position
                // Now check for the next occurrence of 'g' starting from this position
                while (true) {
                    if (s[i] == 'g') {
                        // if we find a green color, we return the total waiting time + 1 (to move on next green)
                        return time_to_wait + 1; 
                    }
                    time_to_wait++; // Increase wait time as we consider the next second
                    i = (i + 1) % n; // Move to the next position in a circular manner
                }
            }
        }
        return -1; // This line should never be reached as per problem guarantees
    }
};


#endif