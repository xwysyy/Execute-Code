#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n);
        for (int i = 1; i <= n; ++i) {
            int required_zeros = i;
            int current_zeros = 0;
            long long operations = 0;
            bool possible = false;
            for (int j = n - 1; j >= 0; --j) {
                if (s[j] == '0') {
                    current_zeros++;
                    if (current_zeros == required_zeros) {
                        possible = true;
                        break;
                    }
                } else {
                    operations += (current_zeros);
                }
            }
            if (possible) {
                result[i - 1] = operations;
            } else {
                result[i - 1] = -1;
            }
        }
        return result;
    }
};


#endif