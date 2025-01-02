#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int removals = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (s.substr(i, 3) == "pie" || s.substr(i, 3) == "map") {
                // If we find "pie" or "map", we'll need to remove at least one character to break it
                removals++;
                // Skip over the substring to avoid re-detecting overlapping substrings
                i += 2;  // Move i forward to skip past this substring
            }
        }
        return removals;
    }
};


#endif