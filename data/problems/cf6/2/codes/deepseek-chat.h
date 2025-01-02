#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Determine the parity of the first element
        int parity_first = a[0] % 2;
        // Determine the parity of the second element
        int parity_second = a[1] % 2;
        
        // Check if all odd-indexed elements have the same parity as the first element
        // and all even-indexed elements have the same parity as the second element
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (a[i] % 2 != parity_first) {
                    return "NO";
                }
            } else {
                if (a[i] % 2 != parity_second) {
                    return "NO";
                }
            }
        }
        
        // If all elements have the same parity, return "YES"
        if (parity_first == parity_second) {
            return "YES";
        }
        
        // Otherwise, check if we can make all elements have the same parity by performing operations
        // We can perform operations to change the parity of either odd or even indexed elements
        // So, if the parity of odd and even indexed elements is different, we can make them the same
        // by performing operations to change the parity of one of them
        return "YES";
    }
};


#endif