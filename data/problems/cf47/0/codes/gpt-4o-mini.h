#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<bool> seats(n + 1, false); // seats[0] is unused
        seats[a[0]] = true; // First passenger can sit anywhere
        
        for (int i = 1; i < a.size(); ++i) {
            int curr_seat = a[i];
            // Check left neighbor
            bool left_occupied = (curr_seat > 1 && seats[curr_seat - 1]);
            // Check right neighbor
            bool right_occupied = (curr_seat < n && seats[curr_seat + 1]);
            
            // A passenger can only sit if at least one neighbor is occupied
            if (!left_occupied && !right_occupied) {
                return "NO"; // Rule violation found
            }
            
            seats[curr_seat] = true; // Mark the seat as occupied
        }
        
        return "YES"; // All passengers followed the rules
    }
};


#endif