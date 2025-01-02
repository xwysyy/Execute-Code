#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {   
        vector<long long> result(n);
        int countZeros = 0;
        
        // Count number of zeros in the string
        for (char c : s) {
            if (c == '0') {
                countZeros++;
            }
        }

        // For each i from 1 to n
        for (int i = 1; i <= n; i++) {
            if (countZeros < i) {
                // Not enough zeros to make divisible by 2^i
                result[i-1] = -1;
            } else {
                // We need to move at least i zeros to the end
                long long swaps = 0;
                int zerosToMove = i;
                int pos = n - 1;

                // Traverse the string from the end
                for (int j = n - 1; j >= 0 && zerosToMove > 0; j--) {
                    if (s[j] == '0') {
                        // We found a zero that can be moved to the end
                        swaps += (pos - j); // Count how many swaps it would take
                        pos--; // Move the next zero target position left
                        zerosToMove--; // One less zero to move
                    }
                }

                result[i-1] = swaps;
            }
        }

        return result;
    }
};


#endif