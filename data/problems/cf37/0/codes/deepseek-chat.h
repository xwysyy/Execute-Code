#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int removeCount = 0;
        for (int i = 0; i < n - 2; ++i) {
            string substring = s.substr(i, 3);
            if (substring == "pie" || substring == "map") {
                removeCount++;
                i += 2; // Skip the next two characters to avoid overlapping substrings
            }
        }
        return removeCount;
    }
};


#endif