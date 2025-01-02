#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> result;
        for (int i = 0; i < q; i++) {
            int num_players = n[i];
            vector<bool> eliminated(num_players + 1, false);
            int eliminated_count = 0;

            while (true) {
                int round_eliminated = 0;
                for (int j = 0; j < k; j++) {
                    int target_player = a[j] - eliminated_count;
                    if (target_player > 0 && target_player <= num_players - eliminated_count) {
                        int current_player = 0;
                        for (int l = 1; l <= num_players; l++) {
                            if (!eliminated[l]) {
                                current_player++;
                            }
                            if (current_player == target_player) {
                                eliminated[l] = true;
                                eliminated_count++;
                                round_eliminated++;
                                break;
                            }
                        }
                    }
                }
                if (round_eliminated == 0) {
                    break;
                }
            }
            result.push_back(num_players - eliminated_count);
        }
        return result;
    }
};


#endif