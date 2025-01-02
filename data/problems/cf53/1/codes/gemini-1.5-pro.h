#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int count = 0;
        map<int, int> freq;
        for (int x : a) {
            freq[x]++;
        }

        int max_freq = 0;
        for (auto const& [key, val] : freq) {
            max_freq = max(max_freq, val);
        }

        if (max_freq <= n / 2) {
            for (int i = 0; i < n - 1; ++i) {
                if (a[i] == a[i + 1]) {
                    count++;
                }
            }
            return count;
        }

        int min_disturbance = n;
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
};


#endif