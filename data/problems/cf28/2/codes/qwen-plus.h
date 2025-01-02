#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {   
        int n = a.size();
        vector<int> maxOneA(n), maxOneB(n);
        vector<int> minOneA(n), minOneB(n);

        // Fill maxOne and minOne arrays for both strings
        int lastOneA = -1, lastOneB = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') lastOneA = i;
            if (b[i] == '1') lastOneB = i;
            maxOneA[i] = lastOneA;
            maxOneB[i] = lastOneB;
        }

        lastOneA = lastOneB = n;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == '1') lastOneA = i;
            if (b[i] == '1') lastOneB = i;
            minOneA[i] = lastOneA;
            minOneB[i] = lastOneB;
        }

        // Check if the transformation is possible
        for (int i = 0; i < n; ++i) {
            if ((maxOneA[i] >= 0 && minOneB[i] < n && maxOneA[i] <= minOneB[i]) ||
                (maxOneB[i] >= 0 && minOneA[i] < n && maxOneB[i] <= minOneA[i])) {
                continue;
            } else {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif