#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long inversions = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    inversions++;
                }
            }
        }

        long long max_inversions = inversions;

        for (int i = 0; i < n; i++) {
            long long current_inversions = 0;
            vector<int> b = a;
            b[i] = 1 - b[i];
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (b[j] > b[k]) {
                        current_inversions++;
                    }
                }
            }
            max_inversions = max(max_inversions, current_inversions);
        }

        return max_inversions;
    }
};


#endif