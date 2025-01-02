#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, std::vector<int> &a) {
        std::sort(a.begin(), a.end());

        long long min_cost = LONG_LONG_MAX;
        int max_possible_permutation = std::min(n, a.back());
        
        std::unordered_set<int> seen;
        int used = 0;

        for (int i = 1; i <= max_possible_permutation; ++i) {
            while (used < n && a[used] < i) {
                ++used;
            }

            int excess = n - used;
            int missing = i - used;
            long long cost = (long long)excess * c + (long long)missing * d;

            min_cost = std::min(min_cost, cost);

            if (used < n && a[used] == i) {
                ++used;
            }
        }

        // Consider the case where the whole array needs to be removed and insert a new permutation entirely
        min_cost = std::min(min_cost, (long long)n * c + d);

        return min_cost;
    }
};


#endif