#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        sort(a.begin(), a.end());
        long long max_petals = 0;
        for (int i = 0; i < n; ++i) {
            long long cost = 0;
            long long petals = 0;
            int j = i;
            while (j < n && a[j] - a[i] <= 1) {
                cost += a[j];
                petals += a[j];
                if (cost > m) break;
                j++;
            }
            max_petals = max(max_petals, petals);
        }
        return max_petals;
    }
};

#endif