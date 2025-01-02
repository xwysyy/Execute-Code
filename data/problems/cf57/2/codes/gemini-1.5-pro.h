#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        int res = 0;
        map<int, vector<int>> brands;
        for (auto& p : b) {
            brands[p.first].push_back(p.second);
        }
        for (auto& entry : brands) {
            sort(entry.second.rbegin(), entry.second.rend());
        }
        vector<int> sums;
        for (auto& entry : brands) {
            int sum = 0;
            for (int i = 0; i < entry.second.size(); ++i) {
                sum += entry.second[i];
                sums.push_back(sum);
            }
        }
        sort(sums.rbegin(), sums.rend());
        for (int i = 0; i < min((int)sums.size(), n); ++i) {
            res += sums[i];
        }
        return res;
    }
};


#endif