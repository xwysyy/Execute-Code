#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        vector<bool> occupied(n + 2, false); // Extra padding to avoid boundary checks
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            if (i > 0 && !occupied[seat - 1] && !occupied[seat + 1]) {
                return "NO";
            }
            occupied[seat] = true;
        }
        return "YES";
    }
};


#endif