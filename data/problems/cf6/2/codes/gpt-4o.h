#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string solve(int &n, std::vector<int> &a) {
        // Flags to check parity consistency
        bool oddIndexParityInitialized = false, evenIndexParityInitialized = false;
        bool oddParityEven = false, evenParityEven = false;
        
        // Check parity of elements at odd indices and even indices
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // Even index (0-based)
                if (!evenIndexParityInitialized) {
                    evenParityEven = (a[i] % 2 == 0);
                    evenIndexParityInitialized = true;
                } else if (evenParityEven != (a[i] % 2 == 0)) {
                    return "NO"; // Inconsistent parity for even index elements
                }
            } else { // Odd index (0-based)
                if (!oddIndexParityInitialized) {
                    oddParityEven = (a[i] % 2 == 0);
                    oddIndexParityInitialized = true;
                } else if (oddParityEven != (a[i] % 2 == 0)) {
                    return "NO"; // Inconsistent parity for odd index elements
                }
            }
        }
        
        // If we made through the checks without inconsistency, it's possible to achieve uniform parity
        return "YES";
    }
};


#endif