#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n, 0);
        int ones = 0;
        
        // Count the number of 1's in the binary string
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }
        
        // If there are no 1's, the number is already divisible by any power of 2
        if (ones == 0) {
            return result;
        }
        
        // For each i from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Find the position of the i-th bit from the right
            int pos = n - i;
            
            // If the i-th bit from the right is 0, we need to find the nearest 1 to the left of this position
            if (s[pos] == '0') {
                int count = 0;
                for (int j = pos - 1; j >= 0; --j) {
                    if (s[j] == '1') {
                        result[i - 1] = count + 1;
                        break;
                    }
                    count++;
                }
                if (result[i - 1] == 0) {
                    result[i - 1] = -1;
                }
            } else {
                // If the i-th bit from the right is 1, it is impossible to make the number divisible by 2^i
                result[i - 1] = -1;
            }
        }
        
        return result;
    }
};

#endif