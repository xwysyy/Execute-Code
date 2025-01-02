#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> frequency;
        for (int i = 0; i < n; i++) {
            frequency[a[i]]++;
            if (frequency[a[i]] >= 3) {
                return a[i];
            }
        }
        return -1;
    }
};

#endif