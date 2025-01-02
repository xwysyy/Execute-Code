#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &t, vector<int> &a, vector<int> &b) {   
        int best_video_index = -1;
        int max_entertainment = -1;
        
        for (int i = 0; i < n; i++) {
            int time_to_watch = i + a[i];
            
            if (time_to_watch <= t) {
                if (b[i] > max_entertainment) {
                    max_entertainment = b[i];
                    best_video_index = i;
                }
            }
        }
        
        // Return the result, adjusting for 1-based index return requirement
        return best_video_index + 1;
    }
};


#endif