#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        sort(a.begin(), a.end());
        long long max_petals = 0;
        long long current_sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            current_sum += a[right];
            while (a[right] - a[left] > 1) {
                current_sum -= a[left];
                left++;
            }
            if (current_sum <= m) {
                max_petals = max(max_petals, current_sum);
            } else {
                while (current_sum > m && left <= right) {
                    current_sum -= a[left];
                    left++;
                }
                if (current_sum <= m) {
                    max_petals = max(max_petals, current_sum);
                }
            }
        }

        return max_petals;
    }
};


#endif