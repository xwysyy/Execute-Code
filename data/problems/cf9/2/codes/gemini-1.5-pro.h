#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> ans;
        for (int k = 0; k < q; k++) {
            long long sum = 0;
            int type = queries[k].first;
            int val = queries[k].second;
            for (int i = 0; i < n; i++) {
                if (type == 0) {
                    if (a[i] % 2 == 0) {
                        a[i] += val;
                    }
                } else {
                    if (a[i] % 2 != 0) {
                        a[i] += val;
                    }
                }
                sum += a[i];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};


#endif