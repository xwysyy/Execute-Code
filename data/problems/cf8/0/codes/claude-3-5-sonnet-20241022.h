#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a, string &s) {
        // Map to store number to character mappings
        unordered_map<int, char> num_to_char;
        // Map to store character to number mappings
        unordered_map<char, int> char_to_num;
        
        // Check each position
        for(int i = 0; i < n; i++) {
            int curr_num = a[i];
            char curr_char = s[i];
            
            // If number is already mapped
            if(num_to_char.count(curr_num)) {
                // Check if it maps to the same character
                if(num_to_char[curr_num] != curr_char) {
                    return "NO";
                }
            }
            // If character is already mapped
            else if(char_to_num.count(curr_char)) {
                // Check if it maps to the same number
                if(char_to_num[curr_char] != curr_num) {
                    return "NO";
                }
            }
            // Create new mapping
            else {
                num_to_char[curr_num] = curr_char;
                char_to_num[curr_char] = curr_num;
            }
        }
        
        return "YES";
    }
};


#endif