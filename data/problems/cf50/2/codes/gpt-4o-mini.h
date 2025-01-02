#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) {
            return a[0] + 1; // Only one element, we can color it
        }
        
        int max_score = 0;

        // Consider two cases: color the first element or not
        int include_first = a[0] + 1; // Color a[0]
        int exclude_first = 0; // Do not color a[0]
        
        for (int i = 1; i < n; i++) {
            int new_include_first = exclude_first + a[i] + 1; // Color a[i]
            int new_exclude_first = max(include_first, exclude_first); // Decide on a[i]
            
            // Update scores
            include_first = new_include_first;
            exclude_first = new_exclude_first;
        }
        
        max_score = max(include_first, exclude_first);
        
        return max_score;
    }
};


#endif