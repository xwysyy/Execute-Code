#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        long long prod = 1;
        for (int x : a) {
            prod *= x;
        }

        long long target = 1;
        for (int i = 0; i < n; ++i) {
            target *= 2;
        }

        if (prod % target == 0) {
            return 0;
        }

        int count = 0;
        vector<int> twos(n + 1);
        for (int i = 1; i <= n; ++i) {
            int temp = i;
            while (temp % 2 == 0) {
                twos[i]++;
                temp /= 2;
            }
        }

        int ops = 0;
        for(int i = 0; i < n; ++i) {
            int temp = a[i];
            int c = 0;
            while(temp % 2 == 0) {
                c++;
                temp /= 2;
            }
            count += c;
        }

        if (count >= n) return 0;

        vector<pair<int, int>> indices;
        for(int i = 1; i <= n; i++){
            indices.push_back({twos[i], i});
        }
        sort(indices.rbegin(), indices.rend());

        for(int i = 0; i < n; i++){
            count += indices[i].first;
            ops++;
            if(count >= n) return ops;
        }

        return -1;

    }
};


#endif