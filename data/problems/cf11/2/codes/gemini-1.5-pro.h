#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        long long product = 1;
        for (int x : a) {
            product *= x;
        }

        long long target = 1;
        for (int i = 0; i < n; ++i) {
            target *= 2;
        }

        if (product % target == 0) {
            return 0;
        }

        int count = 0;
        vector<int> twos(n + 1);
        for (int i = 1; i <= n; ++i) {
            int num = i;
            while (num % 2 == 0) {
                twos[i]++;
                num /= 2;
            }
        }

        int operations = 0;
        for (int i = 1; i <= n; ++i) {
            if (product % target == 0) {
                return operations;
            }
            if (twos[i] > 0) {
                product *= i;
                operations++;
            }
        }


        if (product % target == 0)
            return operations;
        else 
            return -1;
    }
};


#endif