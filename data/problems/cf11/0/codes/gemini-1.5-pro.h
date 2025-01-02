#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        long long prod = 1;
        for (int x : a) {
            prod *= x;
        }
        long long target = 1;
        for (int i = 0; i < n; i++) {
            target *= 2;
        }
        if (prod % target == 0) {
            return 0;
        }
        int count = 0;
        vector<int> indices;
        for (int i = 1; i <= n; i++) {
            int temp = i;
            while (temp % 2 == 0) {
                count++;
                temp /= 2;
            }
            indices.push_back(i);
        }
        int ops = 0;
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            int count_a = 0, count_b = 0;
            int temp_a = a, temp_b = b;
            while (temp_a % 2 == 0) {
                count_a++;
                temp_a /= 2;
            }
            while (temp_b % 2 == 0) {
                count_b++;
                temp_b /= 2;
            }
            return count_a > count_b;
        });

        for(int i = 0; i < n; ++i) {
            if (prod % target == 0) break;
            prod *= indices[i];
            ops++;
        }


        if (prod % target == 0)
            return ops;
        else
            return -1;
    }
};


#endif