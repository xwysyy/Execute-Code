#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        int start = 0;
        int current_sum = 0;
        int max_rounds = 0;
        
        // Traverse through the card values
        for (int end = 0; end < n; ++end) {
            current_sum += a[end];
            
            // Try to manage the sum within the window from start to end
            while (current_sum > r && start <= end) {
                current_sum -= a[start];
                ++start;
            }
            
            // Check if we have a valid round
            if (current_sum >= l && current_sum <= r) {
                ++max_rounds;
                // Reset the window and current sum for a new round
                current_sum = 0;
                start = end + 1; // Move start to the next card
            }
        }
        
        return max_rounds;
    }
};


#endif