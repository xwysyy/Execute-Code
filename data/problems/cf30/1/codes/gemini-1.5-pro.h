#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> ans(n);
        for (int i = 1; i <= n; i++) {
            long long res = 0;
            int cnt = 0;
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    if (s[j] == '1') {
                        res += j - cnt;
                        cnt++;
                    }
                }
                if (j == i -1 && cnt ==0){
                    flag = true;
                    break;
                }

            }

            if (flag){
                ans[i - 1] = -1;
            }
            else {
                ans[i - 1] = res;
            }
            
        }
        return ans;
    }
};


#endif