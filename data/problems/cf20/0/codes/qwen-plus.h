#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int maxEntertainment = -1;
        int bestIndex = -1;
        int currentTime = 0;
        
        for (int i = 0; i < n; ++i) {
            // Calculate the time to start watching the ith video
            currentTime += i;
            
            // Check if we can watch the ith video within the remaining time
            if (currentTime + a[i] <= t) {
                if (b[i] > maxEntertainment) {
                    maxEntertainment = b[i];
                    bestIndex = i;
                }
            } else {
                break;
            }
        }
        
        return bestIndex + 1; // Convert 0-indexed to 1-indexed
    }
};


#endif