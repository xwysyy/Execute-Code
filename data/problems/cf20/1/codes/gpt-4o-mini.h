#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int maxEntertainment = -1;
        int bestIndex = -1;

        for (int i = 0; i < n; i++) {
            int total_time = a[i] + i; // i represents the index starting from 0, so (i + 1 - 1)
            if (total_time <= t) {
                if (b[i] > maxEntertainment) {
                    maxEntertainment = b[i];
                    bestIndex = i + 1; // Return the index in 1-based format
                }
            }
        }

        return bestIndex; // If no valid video found, returned value will be -1 initialized
    }
};


#endif