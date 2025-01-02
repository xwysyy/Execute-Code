#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<bool> occupied(n + 1, false); // To keep track of occupied seats
        occupied[a[0]] = true; // First passenger can sit anywhere
        for (int i = 1; i < n; ++i) {
            int seat = a[i];
            bool valid = false;
            // Check if at least one neighboring seat is occupied
            if (seat > 1 && occupied[seat - 1]) {
                valid = true;
            }
            if (seat < n && occupied[seat + 1]) {
                valid = true;
            }
            if (!valid) {
                return "NO";
            }
            occupied[seat] = true;
        }
        return "YES";
    }
};


#endif