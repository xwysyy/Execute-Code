#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        long long ans = (long long)n * d; // Cost to remove all and insert 1 to n
        map<int, int> freq;
        for (int x : a) {
            freq[x]++;
        }

        int len = 0;
        for (int i = 1; ; ++i) {
            if (freq.count(i)) {
                len++;
            } else {
                break;
            }
        }

        ans = min(ans, (long long)(n - len) * d + (long long)(n - len) * c);


        for (int target_len = 1; target_len <= n; ++target_len) {
            long long cur_cost = 0;
            int elements_to_remove = 0;
            int elements_to_add = 0;

            for (int i = 1; i <= target_len; ++i) {
                if (freq.count(i)) {
                    elements_to_remove += freq[i] - 1;
                } else {
                    elements_to_add++;
                }
            }
            for(auto const& [key, val] : freq) {
                if (key > target_len) {
                    elements_to_remove += val;
                }
            }

            cur_cost = (long long)elements_to_remove * c + (long long)elements_to_add * d;
            ans = min(ans, cur_cost);
        }


        return ans;
    }
};


#endif