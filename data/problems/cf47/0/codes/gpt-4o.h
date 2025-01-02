#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        vector<bool> occupied(n+2, false);   // This array maintains the occupied status of seats.
        
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            
            // Check if this is the first passenger.
            if (i == 0) {
                // The first passenger can sit anywhere.
                occupied[seat] = true;
                continue;
            }
            
            // Check if current seat has at least one neighbor occupied.
            if (!(occupied[seat - 1] || occupied[seat + 1])) {
                return "NO";  // If neither neighbor is occupied, the rule is broken.
            }
            
            // Mark the seat as occupied.
            occupied[seat] = true;
        }
        
        return "YES";  // If all passengers followed the rules, return "YES".
    }
};


#endif