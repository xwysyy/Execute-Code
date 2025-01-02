#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<bool> occupied(n + 2, false);
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            if (i == 0) {
                occupied[seat] = true;
            } else {
                if (!occupied[seat - 1] && !occupied[seat + 1]) {
                    return "NO";
                }
                occupied[seat] = true;
            }
        }
        return "YES";
    }
};


#endif