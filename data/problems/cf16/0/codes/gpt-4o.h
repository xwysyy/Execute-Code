#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // Calculate distance to be covered in x and y
        int max_x = abs(a);
        int max_y = abs(b);
        
        // Minimum basic time without consecutive move constraints
        int min_time = std::max(max_x, max_y);
        
        // Adjust time if parities of distances differ
        if ((max_x % 2) != (max_y % 2)) {
            min_time += 1;
        }
        
        return min_time;
    }
};


#endif