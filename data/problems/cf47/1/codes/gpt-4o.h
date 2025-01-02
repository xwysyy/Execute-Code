#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Initialize an array to keep track of occupied seats
        vector<bool> seats(n + 1, false);
        
        // Process each passenger's seat choice
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            
            // Check seat validity for all but the first passenger
            if (i > 0) {
                // A valid seat must have a neighbor: previous or next seat occupied
                if ((seat > 1 && seats[seat - 1]) || (seat < n && seats[seat + 1])) {
                    // Valid placement, continue
                } else {
                    // Invalid placement found
                    return "NO";
                }
            }
            
            // Mark this seat as occupied
            seats[seat] = true;
        }
        
        // If no invalid placements were found
        return "YES";
    }
};


#endif