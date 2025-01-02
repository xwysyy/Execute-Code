#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int count = 0;
        int sum = 0;
        int i = 0;
        while (i < n) {
            sum = 0;
            int j = i;
            while (j < n) {
                sum += a[j];
                if (sum == 0) {
                    count++;
                    i = j + 1;
                    break;
                }
                j++;
            }
            if (j == n) {
                i = n;
            }
        }
        return count;
    }
};


#endif