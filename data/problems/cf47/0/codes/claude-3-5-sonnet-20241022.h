#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<bool> occupied(n + 1, false);
        
        // First passenger can sit anywhere
        occupied[a[0]] = true;
        
        // Check for each subsequent passenger
        for (int i = 1; i < n; i++) {
            int seat = a[i];
            
            // Check if there's an occupied neighboring seat
            bool hasOccupiedNeighbor = false;
            if (seat > 1 && occupied[seat - 1]) hasOccupiedNeighbor = true;
            if (seat < n && occupied[seat + 1]) hasOccupiedNeighbor = true;
            
            // If no occupied neighbors when required, return "NO"
            if (!hasOccupiedNeighbor) return "NO";
            
            occupied[seat] = true;
        }
        
        return "YES";
    }
};


#endif