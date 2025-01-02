#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        vector<bool> occupied(n + 1, false);
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            if (i == 0) {
                // First passenger can sit anywhere
                occupied[seat] = true;
            } else {
                // Check if the current seat has at least one occupied neighboring seat
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