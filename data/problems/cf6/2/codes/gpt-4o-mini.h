#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        bool odd_parity = true;
        bool even_parity = true;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // even index
                if (a[i] % 2 == 1) {
                    even_parity = false; // found an odd at an even index
                }
            } else { // odd index
                if (a[i] % 2 == 0) {
                    odd_parity = false; // found an even at an odd index
                }
            }
        }

        // If we can make all elements have the same parity.
        if (odd_parity || even_parity) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif