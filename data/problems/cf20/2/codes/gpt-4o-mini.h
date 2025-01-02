#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {
        int maxEntertainment = -1; // Store the max entertainment value found
        int chosenIndex = -1; // Store the index of the chosen video

        for (int i = 0; i < n; i++) {
            // Time needed to watch the video at index i
            int timeRequired = a[i] + i; // a[i] for the video duration, i for skips
            
            // Check if the time required is within the allowed time t
            if (timeRequired <= t) {
                // If valid, check if this video's entertainment value is the highest found
                if (b[i] > maxEntertainment) {
                    maxEntertainment = b[i];
                    chosenIndex = i + 1; // Store 1-based index
                }
            }
        }
        
        return chosenIndex; // Return the index of the most entertaining video, or -1 if none found
    }
};


#endif