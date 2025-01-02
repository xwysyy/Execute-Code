#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Create a copy of array to work with
        vector<int> arr = a;
        int minDist = countDisturbance(arr);
        
        // Try all possible combinations of swaps
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp = a;
            // For each bit in mask, if set, perform the swap
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    swap(temp[i], temp[n-i-1]);
                }
            }
            minDist = min(minDist, countDisturbance(temp));
        }
        
        return minDist;
    }
    
private:
    // Count number of adjacent equal elements
    int countDisturbance(vector<int>& arr) {
        int dist = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                dist++;
            }
        }
        return dist;
    }
};


#endif