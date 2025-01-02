#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Initial states
        int not_red = 0; // DP state for not choosing a[0] as red
        int red = a[0] + 1; // DP state for choosing a[0] as red

        for (int i = 1; i < n; ++i) {
            // Compute new states
            int new_not_red = max(not_red, red);
            int new_red = not_red + a[i] + 1;

            // Update current states
            not_red = new_not_red;
            red = new_red;
        }

        // The result is the maximum score we can get
        return max(not_red, red);
    }
};


#endif