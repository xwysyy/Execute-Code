#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        bool canMakeEven = true;
        bool canMakeOdd = true;
        
        for (int i = 0; i < n; ++i) {
            if ((a[i] + i) % 2 == 0) {
                canMakeOdd = false;
            } else {
                canMakeEven = false;
            }
        }
        
        if (canMakeEven || canMakeOdd) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif