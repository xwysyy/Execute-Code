#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 1) return 1; // if n = 1, a deletion is needed to have an even length

        // Frequency dictionaries for even and odd indexed positions
        unordered_map<char, int> freq_even, freq_odd;
        
        // Fill the frequency maps
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                freq_even[s[i]]++;
            } else {
                freq_odd[s[i]]++;
            }
        }
        
        // Get the maximum frequencies and second maximum for both lists
        int even_max1 = 0, even_max2 = 0, odd_max1 = 0, odd_max2 = 0;
        char even_char1, even_char2, odd_char1, odd_char2;

        for (const auto &pair : freq_even) {
            if (pair.second > even_max1) {
                even_max2 = even_max1;
                even_char2 = even_char1;
                even_max1 = pair.second;
                even_char1 = pair.first;
            } else if (pair.second > even_max2) {
                even_max2 = pair.second;
                even_char2 = pair.first;
            }
        }

        for (const auto &pair : freq_odd) {
            if (pair.second > odd_max1) {
                odd_max2 = odd_max1;
                odd_char2 = odd_char1;
                odd_max1 = pair.second;
                odd_char1 = pair.first;
            } else if (pair.second > odd_max2) {
                odd_max2 = pair.second;
                odd_char2 = pair.first;
            }
        }

        // Case when characters for even and odd are different
        int min_ops = (n % 2 == 0) ? (n / 2 - even_max1 + n / 2 - odd_max1) : INT_MAX;

        // Handle the case where we might need to delete one character
        // If we delete an even indexed character
        if (n > 1) {
            if (even_char1 != odd_char1) { // counts are still valid
                min_ops = min(min_ops, (n / 2 - even_max1 + (n - 1) / 2 - odd_max1));
            }
            // If we delete an odd indexed character
            if (even_char1 != odd_char2) { // counts are still valid
                min_ops = min(min_ops, (n / 2 - even_max1 + (n - 1) / 2 - odd_max2));
            }
        }

        return min_ops;
    }
};


#endif