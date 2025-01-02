#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 1) return 1;  // If there's only 1 character, we need 1 operation to remove it.

        map<char, int> even_count, odd_count;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_count[s[i]]++;
            } else {
                odd_count[s[i]]++;
            }
        }

        // Find the maximum frequency in even and odd counts
        int max_even_freq = 0, max_odd_freq = 0;
        for (const auto& pair : even_count) {
            max_even_freq = max(max_even_freq, pair.second);
        }
        for (const auto& pair : odd_count) {
            max_odd_freq = max(max_odd_freq, pair.second);
        }

        // Calculating the number of replacements needed
        int even_positions_needed = (n + 1) / 2; // Cumulative length of even positions
        int odd_positions_needed = n / 2;        // Cumulative length of odd positions

        int replacements = (even_positions_needed - max_even_freq) + (odd_positions_needed - max_odd_freq);
        
        // If the length is odd, consider the option of deleting one character
        if (n % 2 != 0) {
            return min(replacements + 1, replacements); // One operation for deletion can be added
        }

        return replacements; // Total replacements needed
    }
};


#endif