#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        if (n == 1) return "YES"; // If there's only one seat, it's always valid.
        
        vector<bool> occupied(n + 2, false); // To mark seats as occupied. Size n+2 to handle edge cases easily.
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            if (i > 0 && !occupied[seat - 1] && !occupied[seat + 1]) {
                return "NO"; // If this is not the first passenger and neither neighboring seat is occupied.
            }
            occupied[seat] = true; // Mark the current seat as occupied.
        }
        return "YES";
    }
};


#endif