#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        bool has_one_a = false, has_zero_a = false;
        bool has_one_b = false, has_zero_b = false;
        
        // Scan string a for the presence of at least one '0' and one '1'
        for (char c : a) {
            if (c == '0') has_zero_a = true;
            if (c == '1') has_one_a = true;
        }
        
        // Scan string b for the presence of at least one '0' and one '1'
        for (char c : b) {
            if (c == '0') has_zero_b = true;
            if (c == '1') has_one_b = true;
        }
        
        // If both strings have at least one '0' and one '1', return "YES"
        if (has_one_a && has_zero_a && has_one_b && has_zero_b) {
            return "YES";
        }
        
        // Otherwise return "NO"
        return "NO";
    }
};


#endif