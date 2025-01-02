#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Create a set to keep track of occupied seats
        unordered_set<int> occupied;
        
        // Iterate through the array of seat numbers
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            // Check if the seat is already occupied
            if (occupied.find(seat) != occupied.end()) {
                return "NO";
            }
            // If it's not the first passenger, check the neighboring seats
            if (i > 0) {
                bool hasNeighbor = false;
                if (seat > 1 && occupied.find(seat - 1) != occupied.end()) {
                    hasNeighbor = true;
                }
                if (seat < n && occupied.find(seat + 1) != occupied.end()) {
                    hasNeighbor = true;
                }
                if (!hasNeighbor) {
                    return "NO";
                }
            }
            // Mark the seat as occupied
            occupied.insert(seat);
        }
        return "YES";
    }
};


#endif