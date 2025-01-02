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

        if (max_count == n) {
            return n;
        }

        map<int, int> potential_counts;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                potential_counts[a[i] + (j + 1)]++;
            }
        }


        int max_potential_count = 0;
        for (auto const& [key, val] : potential_counts) {
            max_potential_count = max(max_potential_count, val / n);
        }

        return max_potential_count;
    }
};


#endif