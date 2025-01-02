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
        // This is because Alice can always choose a facing-up coin in such a way that she leaves an even number of facing-up coins for Bob,
        // and eventually force Bob into a losing position.
        if (upCount % 2 == 1) return "YES";

        // If the number of facing-up coins is even, we need to check if there's a way for Alice to force a win.
        // One key observation is that if there are two adjacent facing-up coins, Alice can remove one and flip the other two,
        // effectively reducing the problem to an odd number of facing-up coins, which means Alice wins.
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U' && (s[(i + n - 1) % n] == 'U' || s[(i + 1) % n] == 'U')) {
                return "YES";
            }
        }

        // If none of the above conditions are met, Bob will win.
        return "NO";
    }
};


#endif