#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n, -1); // Initialize with -1 for the impossible case
        for (int i = 1; i <= n; ++i) {
            int zero_required = i;
            long long swaps = 0;
            int zero_count = 0;
            
            // Traverse from the end of the string backward
            for (int j = n - 1; j >= 0; --j) {
                if (s[j] == '0') {
                    zero_count++;
                    swaps += (n - 1 - (zero_count - 1)) - j;
                }
                
                if (zero_count >= zero_required) {
                    result[i - 1] = swaps; // Found enough zeros
                    break;
                }
            }
        }
        return result;
    }
};


#endif