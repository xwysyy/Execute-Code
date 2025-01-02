#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int max_enjoyment = -1; // To track the maximum entertainment value
        int chosen_index = -1;  // To track the respective index of the chosen video

        for (int i = 0; i < n; i++) {
            // Calculate the time needed to reach and watch video i
            int time_needed = i + a[i]; // i seconds to skip to the i-th video, a[i] seconds to watch it
            if (time_needed <= t) { // Check if it fits in the lunch time
                if (b[i] > max_enjoyment) { // If it's more enjoyable than the current max
                    max_enjoyment = b[i];
                    chosen_index = i + 1; // Index is 1-based
                }
            }
        }

        return chosen_index; // Return the index of the best choice, or -1 if none was found
    }
};


#endif