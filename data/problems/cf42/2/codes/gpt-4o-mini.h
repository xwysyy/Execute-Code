#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
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
        return countU % 2 == 1 ? "YES" : "NO";
    }
};


#endif