#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        int wins = 0;
        long long currentSum = 0;  // Use long long to avoid overflow
        
        for (int i = 0; i < n; i++) {
            currentSum += a[i];
            // Check if currentSum is within range of l to r
            if (currentSum >= l && currentSum <= r) {
                wins++; // We found a win
                currentSum = 0; // Reset current sum for next round
            } else if (currentSum > r) {
                // The current sum exceeds r; we need to drop some cards
                while (currentSum > r && i >= 0) {
                    currentSum -= a[i--]; // Remove cards from the end to try to lower the sum
                }
                // If we exited the loop, check again:
                if (currentSum >= l && currentSum <= r) {
                    wins++; // We found another win
                    currentSum = 0; // Reset current sum for next round
                }
                // If the sum is no longer valid, it means we cannot win anymore, so we keep the loop
            }
        }
        return wins;
    }
};


#endif