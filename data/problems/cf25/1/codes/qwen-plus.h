#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {   
        // Check if there exists a k > 1 such that n = 1 + k + k^2
        for (int k = 2; k * k <= n - 1; ++k) {
            if (1 + k + k * k == n) {
                return "YES";
            }
        }
        return "NO";
    }
};


#endif