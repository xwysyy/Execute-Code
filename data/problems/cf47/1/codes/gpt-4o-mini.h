#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<bool> seats(n + 2, false); // Create a vector to handle seat occupancy with extra space
        for (int seat : a) {
            seats[seat] = true; // Mark the seat as occupied
        }
        
        // For the first passenger, they can sit anywhere
        for (int i = 1; i < a.size(); i++) {
            int currentSeat = a[i];
            // Check if the current seat has adjacent occupied seats
            if (!seats[currentSeat - 1] && !seats[currentSeat + 1]) {
                return "NO"; // If no neighbors are occupied, return "NO"
            }
        }
        
        return "YES"; // All passengers followed the recommendations
    }
};


#endif