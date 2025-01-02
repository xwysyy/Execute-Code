#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        // Step 1: Coordinate compression preparation
        set<int> allValues(a.begin(), a.end());
        for (const auto& op : ops) {
            allValues.insert(op[1]);
            allValues.insert(op[2]);
        }
        
        // Make a map for coordinate compression
        map<int, int> compressMap;
        int index = 0;
        for (int val : allValues) {
            compressMap[val] = index++;
        }
        
        // Step 2: Initialize the difference array
        vector<int> diff(index + 1, 0);
        
        // Step 3: Apply operations with the difference array
        vector<int> result;
        
        for (const auto& op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];
            
            // Get the compressed indices
            int lIndex = compressMap[l];
            int rIndex = compressMap[r];
            
            // Apply operation in the difference array
            if (type == 1) {
                diff[lIndex]++;
                if (rIndex + 1 <= index) {
                    diff[rIndex + 1]--;
                }
            } else if (type == 2) {
                diff[lIndex]--;
                if (rIndex + 1 <= index) {
                    diff[rIndex + 1]++;
                }
            }
            
            // Step 4: Calculate the new values and the max after the operation
            vector<int> currentA(n);
            int currentMax = INT_MIN;
            
            // Build the actual array from the difference array
            int currentDelta = 0;
            for (int i = 0; i < index; i++) {
                currentDelta += diff[i];
                // For every value that was originally a[i]
                for (int j = 0; j < n; j++) {
                    if (compressMap[a[j]] == i) {
                        currentA[j] = a[j] + currentDelta;
                        currentMax = max(currentMax, currentA[j]);
                    }
                }
            }
            
            result.push_back(currentMax);
        }
        
        return result;
    }
};


#endif