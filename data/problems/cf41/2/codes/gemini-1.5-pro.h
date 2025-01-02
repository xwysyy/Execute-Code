#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> ans;
        for (int i = 0; i < q; i++) {
            int num_players = n[i];
            vector<bool> eliminated(num_players + 1, false);
            int eliminated_count = 0;

            while (true) {
                int round_eliminated = 0;
                for (int j = 0; j < k; j++) {
                    int player_index = a[j] - eliminated_count;
                    if (player_index > 0 && player_index <= num_players - eliminated_count) {
                        int actual_index = 0;
                        int count = 0;
                        for(int l=1; l<=num_players; ++l){
                            if(!eliminated[l]){
                                count++;
                                if(count == player_index){
                                    actual_index = l;
                                    break;
                                }
                            }
                        }
                        
                        if (!eliminated[actual_index]) {
                            eliminated[actual_index] = true;
                            eliminated_count++;
                            round_eliminated++;
                        }
                    }
                }
                if (round_eliminated == 0) {
                    break;
                }
            }
            ans.push_back(num_players - eliminated_count);
        }
        return ans;
    }
};


#endif