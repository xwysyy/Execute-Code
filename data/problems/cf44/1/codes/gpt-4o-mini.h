#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &l, int &r, vector<int> &a) {
        int rounds = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];

            // Check if the sum is within winning range
            if (sum >= l && sum <= r) {
                rounds++;
                sum = 0; // Reset sum for the next round
            }
            // If the sum exceeds r, also reset to avoid overshooting
            else if (sum > r) {
                sum = 0; // Just reset, as this round can't win anymore
            }
        }

        return rounds;
    }
};


#endif