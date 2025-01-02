#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int countU = 0;
        
        // Count the number of 'U' coins
        for (char c : s) {
            if (c == 'U') {
                countU++;
            }
        }
        
        // Determine winner based on the count of 'U'
        if (countU % 2 == 1) {
            return "YES";  // Alice wins
        } else {
            return "NO";   // Bob wins
        }
    }
};


#endif