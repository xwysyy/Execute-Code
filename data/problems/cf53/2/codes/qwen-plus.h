#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int disturbance = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                disturbance++;
            }
        }

        for (int i = 0; i < n / 2; ++i) {
            int left = a[i];
            int right = a[n - i - 1];
            if (left == right) continue;

            int new_disturbance = disturbance;
            int prev_left = (i > 0) ? a[i - 1] : -1;
            int next_right = (i < n - 1) ? a[i + 1] : -1;
            int prev_right = (i < n - 2) ? a[n - i - 2] : -1;
            int next_left = (i < n - 1) ? a[i + 1] : -1;

            // Adjust disturbance count based on the swap
            if (left == next_left) new_disturbance--;
            if (right == prev_right) new_disturbance--;
            if (left == prev_right) new_disturbance++;
            if (right == next_left) new_disturbance++;

            disturbance = min(disturbance, new_disturbance);
        }

        return disturbance;
    }
};


#endif