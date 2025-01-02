#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        bool oddPossible = true, evenPossible = true;
        for (int i = 0; i < n; ++i) {
            if ((a[i] + i) % 2 != 0) {
                evenPossible = false;
            }
            if ((a[i] + i) % 2 != 1) {
                oddPossible = false;
            }
        }
        if (oddPossible || evenPossible) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif