#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n, 0);
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        for (int i = 1; i <= n; i++) {
            int pos = -1;
            for (int j = n - i; j >= 0; j--) {
                if (s[j] == '1') {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                result[i - 1] = -1;
            } else {
                result[i - 1] = (n - i - pos) + (ones - 1);
                ones--;
                s[pos] = '0';
            }
        }
        return result;
    }
};

#endif