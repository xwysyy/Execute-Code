#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        int row_distance = abs(a);
        int col_distance = abs(b);
        int total_distance = row_distance + col_distance;
        
        // If total_distance is even, return it directly, else add an additional second for the skip
        return total_distance + (total_distance % 2);
    }
};


#endif