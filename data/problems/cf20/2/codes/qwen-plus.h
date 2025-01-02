#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int bestIndex = -1;
        int maxEntertainment = -1;
        int remainingTime = t;
        
        for (int i = 0; i < n; ++i) {
            // Subtract the time it takes to skip to this video
            remainingTime -= i;
            if (remainingTime < 0) break;
            
            // Check if we can watch this video within the remaining time
            if (a[i] <= remainingTime && b[i] > maxEntertainment) {
                maxEntertainment = b[i];
                bestIndex = i + 1; // Videos are 1-indexed
            }
            remainingTime += i; // Reset the remaining time for the next iteration
        }
        
        return bestIndex;
    }
};


#endif