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
            remainingTime -= i; // Subtract the time spent skipping to this video
            if (remainingTime >= a[i] && b[i] > maxEntertainment) {
                maxEntertainment = b[i];
                bestIndex = i + 1; // Videos are 1-indexed
            }
            remainingTime += i; // Restore the remaining time for next iteration
        }
        
        return bestIndex;
    }
};


#endif