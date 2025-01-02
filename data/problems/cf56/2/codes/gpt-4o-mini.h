#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int timarUses = 0;
        int i = 0;

        while (i < n) {
            // Check if the current position is a weak spot
            if (s[i] == '0') {
                // Find the end of the weak segment
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                int length_of_weak_segment = i - start;

                // Calculate how many Timar uses are needed
                // The real action needs to avoid m consecutive zeros
                int needed = (length_of_weak_segment - m) / (k - m + 1) + 1;
                timarUses += max(0, needed);

                // Move the index to end of the current weak segment
                i = start + length_of_weak_segment;
            } else {
                i++; // Move to the next spot if it's strong
            }
        }
        
        return timarUses;
    }
};


#endif