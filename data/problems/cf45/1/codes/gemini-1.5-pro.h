#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long cur_ans = 0;
            long long cur_cost = 0;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (abs(a[j] - a[i]) <= 1) {
                    if (cur_cost + a[j] <= m) {
                        cur_cost += a[j];
                        cur_ans += a[j];
                        cnt++;
                    }
                }
            }
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};


#endif