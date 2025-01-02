#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "YES";
        for (int k = 2; k <= n; ++k) {
            if ((n - 1) % k == 0) {
                return "YES";
            }
        }
        return "NO";
    }
};


#endif