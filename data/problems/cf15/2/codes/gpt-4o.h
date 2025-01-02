#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {   
        vector<int> result(n);
        int current_max = a[0];
        int count_max = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == current_max) {
                count_max++;
            } else {
                current_max = a[i];
                count_max = 1;
            }
            result[i] = count_max;
        }
        
        return result;
    }
};


#endif