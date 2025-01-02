#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even += a[i] % 2;
            } else {
                odd += a[i] % 2;
            }
        }
        if (even == 0 || odd == 0) {
            return "YES";
        } else {
            return "NO";
        }
    }
};

#endif