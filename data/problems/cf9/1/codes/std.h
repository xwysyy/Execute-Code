#ifndef STD_H
#define STD_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries)
    {
        int cnt[2]{};
        long long sum[2]{};

        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            cnt[x % 2]++;
            sum[x % 2] += x;
        }
        vector<long long> ans;
        for (int i = 0; i < q; i++)
        {
            int t = queries[i].first;
            int x = queries[i].second;
            sum[t] += 1LL * x * cnt[t];
            if (x % 2)
            {
                cnt[!t] += cnt[t];
                sum[!t] += sum[t];
                cnt[t] = sum[t] = 0;
            }
            ans.push_back(sum[0] + sum[1]);
        }
        return ans;
    }
};



#endif