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
            for (int j = i; j < n; ++j) {
                if (j > i && a[j] - a[j - 1] > 1) break;
                long long cost = 1LL * a[j];
                if (cur_cost + cost <= m) {
                    cur_cost += cost;
                    cur_ans += cost;
                    cnt++;
                } else {
                    break;
                }
            }
            ans = max(ans, cur_ans);

        }
        return ans;
    }
};


#endif