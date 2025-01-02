#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int open_queries = 0;
        
        for (char c : s) {
            if (c == 'Q') {
                open_queries++;
            } else if (c == 'A') {
                if (open_queries > 0) {
                    open_queries--;
                }
            }
        }
        
        // If open_queries is 0 or more (which means we handled all possible rules), it's valid.
        return "YES";
    }
};


#endif