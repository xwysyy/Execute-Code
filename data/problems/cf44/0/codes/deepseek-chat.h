#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        int count = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum >= l && sum <= r) {
                count++;
                sum = 0; // Reset sum for the next round
            } else if (sum > r) {
                sum = a[i]; // Start a new round with the current card
                if (sum >= l && sum <= r) {
                    count++;
                    sum = 0;
                }
            }
        }
        return count;
    }
};


#endif