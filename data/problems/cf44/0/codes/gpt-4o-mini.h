#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        int current_sum = 0;
        int rounds_won = 0;
        
        for (int i = 0; i < n; i++) {
            current_sum += a[i];
            
            // Check if we have a winning round
            if (current_sum >= l && current_sum <= r) {
                rounds_won++;
                current_sum = 0; // Reset for the next round
            } else if (current_sum > r) {
                current_sum = 0; // Over limit, reset
            }
        }
        
        return rounds_won;
    }
};


#endif