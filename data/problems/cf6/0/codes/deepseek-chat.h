#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Determine the parity of the first element
        bool parityFirst = a[0] % 2;
        // Determine the parity of the second element
        bool paritySecond = a[1] % 2;
        
        // Check if all odd-indexed elements have the same parity as the first element
        // and all even-indexed elements have the same parity as the second element
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (a[i] % 2 != parityFirst) {
                    return "NO";
                }
            } else {
                if (a[i] % 2 != paritySecond) {
                    return "NO";
                }
            }
        }
        
        // If all elements have the same parity, return "YES"
        if (parityFirst == paritySecond) {
            return "YES";
        }
        
        // If the parities of odd and even indexed elements are different,
        // we can perform operations to make them the same
        return "YES";
    }
};


#endif