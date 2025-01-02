#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        sort(a.begin(), a.end());
        for (int i = 0; i < k; ++i) {
            if (a[i] < 0) {
                a[i] = 0; 
            } else {
                break;
            }
        }
        for (int i = 0; i < x; ++i) {
            if (a[i] > 0)
                a[i] *= -1;
            else 
                break;

        }
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        return sum;
    }
};


#endif