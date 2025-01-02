#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 1) 
            return 1; // If the string is length 1, one removal operation is needed

        // Option 1: Without performing a delete operation, just replacements
        if (n % 2 == 0) {
            int even_needed = 0, odd_needed = 0;

            // Check consistency
            char even_char = s[0];
            char odd_char = s[1];

            for (int i = 0; i < n; i += 2) {
                if (s[i] != even_char) 
                    even_needed++;
            }

            for (int i = 1; i < n; i += 2) {
                if (s[i] != odd_char) 
                    odd_needed++;
            }

            return even_needed + odd_needed;
        }

        // Option 2: Perform a deletion and then check
        int min_operations = INT_MAX;

        // We try deleting each character to see which results in the fewest necessary replacements
        for (int del = 0; del < n; ++del) {
            int even_needed = 0, odd_needed = 0;

            // Ensure we count replacements correctly after a supposed deletion
            int even_index = 0, odd_index = 1;
            char even_char = (del != 0 ? s[0] : (n > 1 ? s[1] : '\0'));
            char odd_char = (del != 1 ? s[1] : s[2]);

            for (int i = 0; i < n; ++i) {
                if (i == del) continue;
                
                if ((i < del) ? (i % 2 == 0) : ((i-1) % 2 == 0)) // even position
                    if (s[i] != even_char) 
                        even_needed++;
                    
                if ((i < del) ? (i % 2 != 0) : ((i-1) % 2 != 0)) // odd position
                    if (s[i] != odd_char) 
                        odd_needed++;
            }

            int operations = even_needed + odd_needed;
            min_operations = std::min(min_operations, operations);
        }
        
        return min_operations;
    }
};


#endif