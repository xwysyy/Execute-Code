#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> result(q);
        for (int i = 0; i < q; ++i) {
            int current_n = n[i];
            while (true) {
                int count = 0;
                for (int j = 0; j < k; ++j) {
                    if (a[j] <= current_n) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 0) {
                    break;
                }
                current_n -= count;
            }
            result[i] = current_n;
        }
        return result;
    }
};


#endif