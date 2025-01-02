#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        int unansweredQueries = 0;

        for(char c : s) {
            if (c == 'Q') {
                unansweredQueries++;
            } else if (c == 'A') {
                if (unansweredQueries > 0) {
                    unansweredQueries--;
                }
            }
        }

        // After processing all messages, check if any query is left unanswered
        return unansweredQueries == 0 ? "YES" : "NO";
    }
};


#endif