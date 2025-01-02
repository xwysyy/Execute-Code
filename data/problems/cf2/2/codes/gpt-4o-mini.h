#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        // Count the number of `>` and `<`
        int count_greater = 0;
        int count_less = 0;

        for (char c : s) {
            if (c == '>') count_greater++;
            else if (c == '<') count_less++;
        }

        // If there are no '>' or no '<', all rooms are returnable
        if (count_greater == 0 || count_less == 0) {
            return n;
        }

        // If there are both '>' and '<', we must count returnable rooms
        int returnable_count = 0;
        
        for (int i = 0; i < n; i++) {
            // Any room where it can exit one way and come back
            if (s[i] == '-' || (s[i] == '>' && s[(i + 1) % n] != '<') || (s[i] == '<' && s[(i - 1 + n) % n] != '>')) {
                returnable_count++;
            }
        }

        return returnable_count;
    }
};


#endif