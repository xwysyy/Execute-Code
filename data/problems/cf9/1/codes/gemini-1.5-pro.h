#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> ans;
        for (int i = 0; i < q; i++) {
            long long sum = 0;
            int type = queries[i].first;
            int val = queries[i].second;
            for (int j = 0; j < n; j++) {
                if (type == 0 && a[j] % 2 == 0) {
                    a[j] += val;
                } else if (type == 1 && a[j] % 2 != 0) {
                    a[j] += val;
                }
                sum += a[j];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


#endif