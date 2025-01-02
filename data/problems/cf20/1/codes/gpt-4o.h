#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int best_index = -1;
        int best_value = -1;

        for (int i = 0; i < n; ++i) {
            int time_used = a[i] + i; // As i is 0-indexed, effectively (i + 1) - 1
            if (time_used <= t) {
                // Check if this video has a better entertainment value than the previously best found
                if (b[i] > best_value) {
                    best_value = b[i];
                    best_index = i + 1; // Convert to 1-based index
                }
            }
        }
        
        return best_index;
    }
};


#endif