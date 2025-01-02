#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        sort(a.begin(), a.end());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i < k && a[i] < 0) {
                continue;
            }
            sum += a[i];
        }
        int count = 0;
        for (int i = 0; i < n - k; i++) {
            if (count < x && a[i + k] > 0) {
                sum -= 2 * a[i + k];
                count++;
            } else {
                break;
            }
        }

        return sum;
    }
};


#endif