#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        long long cost = 0;
        vector<int> freq(n + 1, 0);
        int elements_to_remove = 0;
        for (int x : a) {
            if (x >= 1 && x <= n) {
                freq[x]++;
            } else {
                elements_to_remove++;
            }
        }

        int missing_elements = 0;
        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 0) {
                missing_elements++;
            } else if (freq[i] > 1) {
                elements_to_remove += (freq[i] - 1);
            }
        }

        cost = (long long)elements_to_remove * c;
        long long cost2 = (long long)missing_elements * d;

        return min(cost + cost2, (long long)n * d + (long long) (a.size()) * c);


    }
};


#endif