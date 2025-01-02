#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        long long current_factors_of_2 = 0;
        vector<int> contributions;

        // Count the number of factors of 2 in the current product
        for (const auto &num : a) {
            int count = 0;
            int x = num;
            while (x % 2 == 0) {
                count++;
                x /= 2;
            }
            current_factors_of_2 += count;
        }

        // If the current factors of 2 are enough
        if (current_factors_of_2 >= n) {
            return 0;
        }

        // Calculate how many additional factors are needed
        int needed_factors = n - current_factors_of_2;

        // Calculate contributions from indices
        for (int i = 1; i <= n; i++) {
            int count = 0;
            int x = i;
            while (x % 2 == 0) {
                count++;
                x /= 2;
            }
            contributions.push_back(count);
        }

        // Sort contributions in descending order
        sort(contributions.begin(), contributions.end(), greater<int>());

        // Determine the minimum number of operations needed
        int operations = 0;
        for (int contribution : contributions) {
            if (needed_factors <= 0) {
                break;
            }
            needed_factors -= contribution;
            operations++;
        }

        return needed_factors > 0 ? -1 : operations;
    }
};


#endif