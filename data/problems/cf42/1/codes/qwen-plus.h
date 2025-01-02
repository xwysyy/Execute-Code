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
        
        // If the number of facing-up coins is odd, Alice wins.
        // This is because Alice can always make a move when it's her turn,
        // and she can force Bob into a position where he has no valid moves.
        if (upCount % 2 == 1) return "YES";
        
        // If the number of facing-up coins is even, we need to check if there are any two adjacent facing-up coins.
        // If there are, Alice can win by removing one of them and flipping the other two adjacent coins.
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U' && (s[(i + 1) % n] == 'U' || s[(i + n - 1) % n] == 'U')) return "YES";
        }
        
        // If none of the above conditions are met, Bob wins.
        return "NO";
    }
};


#endif