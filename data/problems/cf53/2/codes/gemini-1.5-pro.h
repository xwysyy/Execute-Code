#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        map<int, int> counts;
        for (int x : a) {
            counts[x]++;
        }
        int max_count = 0;
        for (auto const& [key, val] : counts) {
            max_count = max(max_count, val);
        }
        int disturbance = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                disturbance++;
            }
        }
        if (max_count > (n + 1) / 2) {
            return disturbance;
        } else {
            int min_disturbance = disturbance;
            for (int i = 0; i < (1 << n); ++i) {
                vector<int> b = a;
                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        swap(b[j], b[n - 1 - j]);
                    }
                }
                int current_disturbance = 0;
                for (int j = 0; j < n - 1; ++j) {
                    if (b[j] == b[j + 1]) {
                        current_disturbance++;
                    }
                }
                min_disturbance = min(min_disturbance, current_disturbance);
            }
            return min_disturbance;
        }
    }
};


#endif