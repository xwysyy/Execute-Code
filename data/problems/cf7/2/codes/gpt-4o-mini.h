#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int magazinesSaved = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                // Safe the magazines in the current box
                magazinesSaved += a[i];
            } else if (i > 0 && s[i - 1] == '1') {
                // If the previous box has a lid, we can move it here
                // hence we save magazines in this box
                magazinesSaved += a[i];
            }
        }
        
        return magazinesSaved;
    }
};


#endif