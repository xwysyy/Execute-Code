#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int max_length = 0;
        for (int i = 0; i < n; ++i) {
            int current_fruits = 0;
            int length = 0;
            for (int j = i; j < n; ++j) {
                if (j > i && h[j - 1] % h[j] != 0) break;
                current_fruits += a[j];
                if (current_fruits > k) break;
                length++;
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }
};


#endif