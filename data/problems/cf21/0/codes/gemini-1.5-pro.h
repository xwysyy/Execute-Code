#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long max_beauty = -1e18; // Initialize with a very small value
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> sub_array;
                sub_array.push_back(a[i]);
                for (int k = i + 1; k <= j; ++k) {
                    sub_array.push_back(a[k]);
                }
                if (sub_array.size() >= 2) {
                    long long current_max_beauty = -1e18;
                    for (int k = 0; k < sub_array.size() - 1; ++k) {
                        current_max_beauty = max(current_max_beauty, (long long)sub_array[k] * sub_array[k + 1]);
                    }
                    max_beauty = max(max_beauty, current_max_beauty);
                }
            }
        }

        
        if (n >= 2) {
            long long current_max_beauty = -1e18;
            for (int i = 0; i < n - 1; ++i) {
                current_max_beauty = max(current_max_beauty, (long long)a[i] * a[i + 1]);
            }
            max_beauty = max(max_beauty, current_max_beauty);
        }

        return max_beauty;
    }
};


#endif