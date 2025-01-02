#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int upCount = 0;
        for (char c : s) {
            if (c == 'U') upCount++;
        }
        
        // If there are no facing-up coins, Alice loses immediately.
        if (upCount == 0) return "NO";
        
        // If the number of facing-up coins is odd, Alice can always win.
        if (upCount % 2 == 1) return "YES";
        
        // If the number of facing-up coins is even, we need to check further.
        bool hasConsecutiveUp = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U' && (s[(i + 1) % n] == 'U' || s[(i - 1 + n) % n] == 'U')) {
                hasConsecutiveUp = true;
                break;
            }
        }
        
        // If there are consecutive facing-up coins, Alice can win.
        if (hasConsecutiveUp) return "YES";
        
        // Otherwise, Bob wins.
        return "NO";
    }
};


#endif