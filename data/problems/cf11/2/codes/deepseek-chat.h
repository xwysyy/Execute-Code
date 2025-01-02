#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int total_factors = 0;
        for (int num : a) {
            while (num % 2 == 0) {
                total_factors++;
                num /= 2;
            }
        }
        if (total_factors >= n) {
            return 0;
        }
        int operations = 0;
        // We need to find the indices that can contribute the most factors of 2
        // Indices that are powers of 2 are the best candidates
        // So we sort the indices in descending order of their power of 2 contribution
        vector<int> indices;
        for (int i = 1; i <= n; ++i) {
            indices.push_back(i);
        }
        // Sort indices based on the number of factors of 2 in i
        sort(indices.begin(), indices.end(), [](int a, int b) {
            int count_a = 0, count_b = 0;
            while (a % 2 == 0) {
                count_a++;
                a /= 2;
            }
            while (b % 2 == 0) {
                count_b++;
                b /= 2;
            }
            return count_a > count_b;
        });
        for (int i : indices) {
            if (total_factors >= n) {
                break;
            }
            int original = a[i-1];
            int new_num = original * i;
            int added_factors = 0;
            while (new_num % 2 == 0) {
                added_factors++;
                new_num /= 2;
            }
            total_factors += added_factors;
            operations++;
        }
        if (total_factors >= n) {
            return operations;
        } else {
            return -1;
        }
    }
};


#endif