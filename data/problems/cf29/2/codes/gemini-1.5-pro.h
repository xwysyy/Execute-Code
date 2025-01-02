#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool valid_subarray = true;
                int current_sum = 0;
                for (int l = i; l <= j; ++l) {
                    current_sum += a[l];
                }
                if (current_sum > k) {
                    continue;
                }
                for (int l = i; l < j; ++l) {
                    if (h[l] % h[l + 1] != 0) {
                        valid_subarray = false;
                        break;
                    }
                }
                if (valid_subarray) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};


#endif