#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        if (n == 1) return "YES"; // If there's only one seat, the rule is trivially followed.
        
        vector<bool> occupied(n + 2, false); // Track occupied seats with buffer to avoid boundary checks
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            if (i > 0 && !occupied[seat - 1] && !occupied[seat + 1]) {
                return "NO"; // If it's not the first passenger and no adjacent seats are occupied
            }
            occupied[seat] = true; // Mark this seat as occupied
        }
        return "YES";
    }
};


#endif