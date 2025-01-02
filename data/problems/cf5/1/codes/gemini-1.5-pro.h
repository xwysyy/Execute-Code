#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> counts;
        for (int x : a) {
            counts[x]++;
            if (counts[x] >= 3) {
                return x;
            }
        }
        return -1;
    }
};


#endif