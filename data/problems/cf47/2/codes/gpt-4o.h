#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        unordered_set<int> occupied;
        
        for (int i = 0; i < n; ++i) {
            int seat = a[i];
            if (i > 0) { // after the first passenger
                // Check if the seat is valid: either the previous or next seat must be occupied
                bool isValid = false;
                if (occupied.count(seat - 1) > 0 || occupied.count(seat + 1) > 0) {
                    isValid = true;
                }
                if (!isValid) {
                    return "NO";
                }
            }
            // Mark the current seat as occupied
            occupied.insert(seat);
        }
        
        return "YES";
    }
};


#endif