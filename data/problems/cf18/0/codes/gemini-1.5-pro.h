#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        long long cost = 0;
        map<int, int> freq;
        for (int x : a) {
            freq[x]++;
        }
        int len = 0;
        for (auto const& [key, val] : freq) {
            if (key >= 1 && key <= n + len) {
                if (val > 1) {
                    cost += (long long)(val - 1) * min(c, d);
                }
               if (key <= n+len) len++;
            } else {
                cost += (long long)val * c;
            }
           
        }
         
        if (len == 0) return (long long) d ;


        long long res = (long long) 1e18;
        for(int k = 1; k <= n+a.size(); k++)
        {
             long long cur_cost = cost;
             int cnt = 0;
            for(auto const&[key, val]:freq)
            {
                if(key >=1 && key <=k) cnt++;
            }
            cur_cost += (long long)max(0,k- cnt)*d;

           
            res = min(res,cur_cost);

        }

        
        
        return res;
    }
};


#endif