#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if array can be sorted in non-increasing order
    // using Stalin Sort on any subarray
    bool isVulnerable(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return true;
        
        // Try all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Create temporary array for the subarray
                vector<int> temp;
                for (int k = 0; k < i; k++)
                    temp.push_back(arr[k]);
                    
                // Apply Stalin Sort on the subarray [i,j]
                int prev = arr[i];
                temp.push_back(prev);
                for (int k = i + 1; k <= j; k++) {
                    if (arr[k] >= prev) {
                        prev = arr[k];
                        temp.push_back(prev);
                    }
                }
                
                // Add remaining elements
                for (int k = j + 1; k < n; k++)
                    temp.push_back(arr[k]);
                    
                // Check if result is in non-increasing order
                bool valid = true;
                for (int k = 1; k < temp.size(); k++) {
                    if (temp[k] > temp[k-1]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }
        }
        return false;
    }
    
    int solve(int &n, vector<int> &a) {
        int result = n;
        // Try all possible combinations of elements to remove
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.push_back(a[i]);
                }
            }
            if (isVulnerable(temp)) {
                result = min(result, n - (int)temp.size());
            }
        }
        return result;
    }
};


#endif