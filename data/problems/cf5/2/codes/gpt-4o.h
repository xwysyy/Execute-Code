#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {   
        if (n == 0) 
            return -1;

        std::unordered_map<int, int> frequency_map;

        for (int i = 0; i < n; ++i) {
            frequency_map[a[i]]++;
            if (frequency_map[a[i]] >= 3) {
                return a[i];
            }
        }

        return -1;  // If no value appears at least 3 times.
    }
};


#endif