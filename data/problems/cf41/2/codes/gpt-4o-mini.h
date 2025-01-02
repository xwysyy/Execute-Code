#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> results(q);
        for (int i = 0; i < q; i++) {
            int current_n = n[i];
            int eliminated = 0;
            while (true) {
                int round_eliminated = 0;
                for (int j = 0; j < k; j++) {
                    if (a[j] <= current_n) {
                        round_eliminated++;
                    }
                }
                if (round_eliminated == 0) {
                    break; // no more eliminations possible
                }
                // Calculate remaining players after this round
                current_n -= round_eliminated;
            }
            results[i] = current_n; // Remaining players are winners
        }
        return results;
    }
};


#endif