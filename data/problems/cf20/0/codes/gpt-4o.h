#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, std::vector<int> &a, std::vector<int> &b) {
        int bestIndex = -1;
        int maxEntertainment = -1;
        
        for (int i = 0; i < n; ++i) {
            int timeToWatch = i + a[i]; // i (skip time) + a[i] (watch time)
            if (timeToWatch <= t) {
                if (b[i] > maxEntertainment) {
                    maxEntertainment = b[i];
                    bestIndex = i + 1;  // Convert 0-based index to 1-based index
                }
            }
        }
        
        return bestIndex;
    }
};


#endif