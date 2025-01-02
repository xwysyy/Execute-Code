#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, std::vector<int> &a) {
        std::unordered_set<int> unique_numbers(a.begin(), a.end());
        long long min_cost = LLONG_MAX;

        // The highest number which could appear in a permutation.
        int max_number = unique_numbers.size() > 0 ? *max_element(unique_numbers.begin(), unique_numbers.end()) : 0;

        // Check potentials for k from 1 to max(unique a's value, unique count)
        for (int k = 1; k <= std::max(max_number, n); k++) {
            long long remove_cost = 0, insert_cost = 0;

            // Compute removals: remove all elements > k
            for (int num : unique_numbers) {
                if (num > k) {
                    remove_cost += c;
                }
            }

            // Compute insertions: insert all integers from 1 to k if they're missing
            for (int num = 1; num <= k; num++) {
                if (unique_numbers.find(num) == unique_numbers.end()) {
                    insert_cost += d;
                }
            }

            // Total cost for this value of k
            long long total_cost = remove_cost + insert_cost;
            min_cost = std::min(min_cost, total_cost);
        }

        return min_cost;
    }
};


#endif