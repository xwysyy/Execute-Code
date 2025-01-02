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
            vector<int> sub = vector<int>(a.begin(), a.begin() + k);
            double max_score = 0.0;
            int max_len = 0;
            for (int i = 0; i < (1 << k); i++) {
                vector<int> subsequence;
                for (int j = 0; j < k; j++) {
                    if ((i >> j) & 1) {
                        subsequence.push_back(sub[j]);
                    }
                }
                int len = subsequence.size();
                if (len == 0) {
                    if (1.0 > max_score) {
                        max_score = 1.0;
                        max_len = 0;
                    } else if (1.0 == max_score) {
                        max_len = max(max_len, 0);
                    }
                } else {
                    double score = 1.0;
                    for (int val : subsequence) {
                        score *= val;
                    }
                    double factorial = 1.0;
                    for (int l = 1; l <= len; l++) {
                        factorial *= l;
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