#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int max_length = 0, current_length = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                current_length++; // increment current length of blanks
            } else {
                max_length = max(max_length, current_length); // update max length if needed
                current_length = 0; // reset for the next segment
            }
        }

        // Final check for the last segment of 0's
        max_length = max(max_length, current_length);

        return max_length;
    }
};


#endif