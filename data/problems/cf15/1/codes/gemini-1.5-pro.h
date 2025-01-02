#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> ans;
        for (int k = 1; k <= n; k++) {
            vector<int> sub_a;
            for (int i = 0; i < k; i++) {
                sub_a.push_back(a[i]);
            }
            double max_score = 0;
            int max_len = 0;
            for (int i = 0; i < (1 << k); i++) {
                vector<int> sub_seq;
                for (int j = 0; j < k; j++) {
                    if ((i >> j) & 1) {
                        sub_seq.push_back(sub_a[j]);
                    }
                }
                int len = sub_seq.size();
                if (len == 0) {
                    if (1 > max_score) {
                        max_score = 1;
                        max_len = 0;
                    } else if (1 == max_score) {
                        max_len = max(max_len, 0);
                    }

                } else {
                    double score = 1;
                    double factorial = 1;
                    for(int j = 0; j < len; j++){
                        score *= sub_seq[j];
                    }
                     for(int j = 1; j <= len; j++){
                        factorial *= j;
                    }
                    score /= factorial;

                    if (score > max_score) {
                        max_score = score;
                        max_len = len;
                    } else if (score == max_score) {
                        max_len = max(max_len, len);
                    }
                }
            }
            ans.push_back(max_len);
        }
        return ans;
    }
};


#endif