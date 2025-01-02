#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) { 
        int max_wins = 0;
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += a[j];
                if (sum >= l && sum <= r) {
                    max_wins++;
                    i = j; // Move to the next round
                    break;
                } else if (sum > r) {
                    i = j; // Skip this round as it exceeds the range
                    break;
                }
            }
        }
        return max_wins;
    }
};

#endif