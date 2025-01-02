#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<bool> occupied(n + 2, false); // Track occupied seats, with padding for boundary checks.

        for (int i = 0; i < a.size(); ++i) {
            int seat = a[i];
            // Check if the current seat can be occupied
            if (i == 0) { // First passenger can sit anywhere
                occupied[seat] = true; // Occupy the seat
            } else {
                // Check adjacent seats
                if (!occupied[seat - 1] && !occupied[seat + 1]) {
                    return "NO"; // The current seat is not adjacent to an occupied seat
                }
                occupied[seat] = true; // Occupy the seat
            }
        }
        
        return "YES"; // All passengers followed the recommendations
    }
};


#endif