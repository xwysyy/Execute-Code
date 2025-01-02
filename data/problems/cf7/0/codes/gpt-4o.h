#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int max_magazines = 0;
        int lastSafeMagazines = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i > 0) {
                    // Consider the bigger of keeping lid current or moving to the previous box.
                    max_magazines += max(a[i], lastSafeMagazines);
                    lastSafeMagazines = a[i];
                } else {
                    // If this is the first box, we can only cover this one.
                    max_magazines += a[i];
                }
            } else {
                // If it's not covered, continue saving last saved information
                // in case next ones can use this box.
                lastSafeMagazines = max(lastSafeMagazines, a[i]);
            }
        }
        
        return max_magazines;
    }
};


#endif