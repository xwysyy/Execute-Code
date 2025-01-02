#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> result(q);
        for (int i = 0; i < q; ++i) {
            int current_n = n[i];
            vector<bool> eliminated(current_n + 1, false);
            int eliminated_count = 0;
            while (true) {
                int current_eliminated = 0;
                for (int j = 0; j < k; ++j) {
                    int index_to_eliminate = a[j] - eliminated_count;
                    if (index_to_eliminate > 0 && index_to_eliminate <= current_n - eliminated_count) {
                        int actual_index = 0;
                        int count = 0;
                        while (count < index_to_eliminate) {
                            actual_index++;
                            if (!eliminated[actual_index]) {
                                count++;
                            }
                        }

                        if (!eliminated[actual_index]) {
                            eliminated[actual_index] = true;
                            eliminated_count++;
                            current_eliminated++;
                        }
                    }
                }
                if (current_eliminated == 0) {
                    break;
                }
            }
            result[i] = current_n - eliminated_count;
        }
        return result;
    }
};


#endif