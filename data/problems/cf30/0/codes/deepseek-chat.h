#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n);
        for (int i = 1; i <= n; ++i) {
            // To make the number divisible by 2^i, the last i bits must be 0.
            // We need to find the positions of the 1s in the last i bits and move them to the left.
            int count = 0;
            long long operations = 0;
            for (int j = n - 1; j >= n - i; --j) {
                if (s[j] == '1') {
                    operations += (n - i - count) - j;
                    count++;
                }
            }
            if (count > 0) {
                result[i - 1] = operations;
            } else {
                result[i - 1] = 0;
            }
            // If it's impossible to make the last i bits 0, return -1.
            if (count > n - i) {
                result[i - 1] = -1;
            }
        }
        return result;
    }
};


#endif