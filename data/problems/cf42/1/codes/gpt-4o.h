#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int countU = 0;
        for (char c : s) {
            if (c == 'U') {
                countU++;
            }
        }
        // If the count of 'U' is odd, Alice can win; if even, Bob can win.
        return (countU % 2 == 1) ? "YES" : "NO";
    }
};


#endif