#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        vector<int> twoPowers(n + 1);
        for (int i = 1; i <= n; ++i) {
            twoPowers[i] = twoPowers[i - 1] + __builtin_ctz(i);
        }

        int totalTwos = 0;
        for (int i = 0; i < n; ++i) {
            totalTwos += __builtin_ctz(a[i]);
        }

        if (totalTwos >= n)
            return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({twoPowers[i + 1], i});
        }

        int operations = 0;
        while (!pq.empty() && totalTwos < n) {
            auto [twos, idx] = pq.top();
            pq.pop();

            totalTwos += twos;
            operations++;

            if (totalTwos >= n)
                break;
        }

        if (totalTwos < n)
            return -1;

        return operations;
    }
};

#endif