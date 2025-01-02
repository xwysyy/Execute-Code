#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {   
        int saved = 0;
        for (int i = 0, lid = 0; i < n; ++i) {
            lid += s[i] - '0'; // Count the number of lids
            if (lid > 0) {
                saved += a[i]; // If there is a lid available, save the magazines in the current box
                --lid; // Use one lid
            }
        }
        return saved;
    }
};

#endif