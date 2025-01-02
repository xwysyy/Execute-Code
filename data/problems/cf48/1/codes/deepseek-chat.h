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
            if (type == 1) {
                for (int i = 0; i < n; ++i) {
                    if (a[i] >= l && a[i] <= r) {
                        a[i]++;
                    }
                }
            } else if (type == 2) {
                for (int i = 0; i < n; ++i) {
                    if (a[i] >= l && a[i] <= r) {
                        a[i]--;
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