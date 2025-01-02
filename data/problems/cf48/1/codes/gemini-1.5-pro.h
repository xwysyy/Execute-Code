#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int type = ops[i][0];
            int l = ops[i][1];
            int r = ops[i][2];
            for (int j = 0; j < n; j++) {
                if (a[j] >= l && a[j] <= r) {
                    if (type == 1) {
                        a[j]++;
                    } else {
                        a[j]--;
                    }
                }
            }
            int max_val = a[0];
            for (int j = 1; j < n; j++) {
                max_val = max(max_val, a[j]);
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};


#endif