#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // If all characters are 'E', it is trivially consistent
        if (count(s.begin(), s.end(), 'E') == n) {
            return "YES";
        }
        
        // In a circular manner, we need to check if there is a sequence of 'N's that covers all.
        // We can rotate the string to check that if there's no complete 'E' wrap,
        // we can just return "YES"
        
        // Append string to itself to simulate circular condition
        string double_s = s + s;
        
        // Find max consecutive 'N's
        int max_seq_n = 0, current_n = 0;
        for (char c : double_s) {
            if (c == 'N') {
                current_n++;
                max_seq_n = max(max_seq_n, current_n);
            } else {
                current_n = 0;
            }
        }
        
        // If max consecutive 'N's (in both strings) < n, then there is at least one 'E' breaking it effectively
        if (max_seq_n < n) {
            return "YES";
        }
        
        return "NO";
    }
};


#endif