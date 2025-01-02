#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s) {
        int removeCount = 0;
        for (int i = 0; i < n; i++) {
            // Check for "pie"
            if (i + 2 < n && s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
                removeCount += 3; // Remove all characters in "pie"
                i += 2; // Move index ahead by 2 to skip the remained characters of "pie"
                continue;
            }
            // Check for "map"
            if (i + 2 < n && s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
                removeCount += 3; // Remove all characters in "map"
                i += 2; // Move index ahead by 2 to skip the remained characters of "map"
                continue;
            }
        }
        
        return removeCount;
    }
};


#endif