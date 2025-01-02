#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n % 2 != 0) {
            // If the length is odd, we need to delete one character to make it even.
            // We will try deleting each character and find the minimum operations required.
            int minOps = INT_MAX;
            for (int i = 0; i < n; ++i) {
                string temp = s;
                temp.erase(i, 1);
                int ops = 0;
                char oddChar = temp[0];
                char evenChar = temp[1];
                for (int j = 0; j < temp.size(); ++j) {
                    if (j % 2 == 0) {
                        if (temp[j] != oddChar) {
                            ops++;
                        }
                    } else {
                        if (temp[j] != evenChar) {
                            ops++;
                        }
                    }
                }
                minOps = min(minOps, ops);
            }
            return minOps + 1; // +1 for the delete operation
        } else {
            // If the length is even, we don't need to delete any character.
            // We just need to make sure that all odd positions have the same character and all even positions have the same character.
            char oddChar = s[0];
            char evenChar = s[1];
            int opsOdd = 0, opsEven = 0;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    if (s[i] != oddChar) {
                        opsOdd++;
                    }
                } else {
                    if (s[i] != evenChar) {
                        opsEven++;
                    }
                }
            }
            // Now, we can also consider swapping the odd and even characters.
            // For example, if the odd positions are 'a' and the even positions are 'b', we can also consider making odd positions 'b' and even positions 'a'.
            char temp = oddChar;
            oddChar = evenChar;
            evenChar = temp;
            int opsOddSwap = 0, opsEvenSwap = 0;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    if (s[i] != oddChar) {
                        opsOddSwap++;
                    }
                } else {
                    if (s[i] != evenChar) {
                        opsEvenSwap++;
                    }
                }
            }
            return min(opsOdd + opsEven, opsOddSwap + opsEvenSwap);
        }
    }
};


#endif