#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        // Sort the array to facilitate the selection of flowers
        sort(a.begin(), a.end());
        
        // Initialize the maximum total number of petals
        long long max_petals = 0;
        
        // Use a sliding window approach to find the maximum sum of petals
        // where the difference between the maximum and minimum petals in the window is at most 1
        long long current_sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            current_sum += a[right];
            
            // Ensure the difference between the maximum and minimum petals in the window is at most 1
            while (a[right] - a[left] > 1) {
                current_sum -= a[left];
                left++;
            }
            
            // If the current sum is within the budget, update the maximum petals
            if (current_sum <= m) {
                max_petals = max(max_petals, current_sum);
            } else {
                // If the current sum exceeds the budget, move the left pointer to reduce the sum
                current_sum -= a[left];
                left++;
            }
        }
        
        return max_petals;
    }
};


#endif