#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, int &m, vector<int> &a, vector<array<int, 3>> &ops) {
        vector<int> result;
        for (const auto& op : ops) {
            int type = op[0];
            int l = op[1];
            int r = op[2];
            for (int i = 0; i < n; ++i) {
                if (a[i] >= l && a[i] <= r) {
                    if (type == 1) {
                        a[i] += 1;
                    } else if (type == 2) {
                        a[i] -= 1;
                    }
                }
            }
            int currentMax = *max_element(a.begin(), a.end());
            result.push_back(currentMax);
        }
        return result;
    }
};


#endif