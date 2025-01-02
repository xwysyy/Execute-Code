#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int max_length = 0;
        int current_length = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                current_length++;
            } else {
                max_length = max(max_length, current_length);
                current_length = 0;
            }
        }
        // Check at the end in case the longest sequence of 0s is at the end
        max_length = max(max_length, current_length);

        return max_length;
    }
};


#endif