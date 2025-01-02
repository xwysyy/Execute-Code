#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // We will check even-indexed and odd-indexed elements separately
        bool oddHasEven = false, oddHasOdd = false;  // For odd indices
        bool evenHasEven = false, evenHasOdd = false; // For even indices

        // Traverse through the array
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) { // Even index (1-based: odd indices in 0-based array)
                if(a[i] % 2 == 0) // This position has even number
                    oddHasEven = true;
                else // This position has odd number
                    oddHasOdd = true;
            } else { // Odd index (1-based: even indices in 0-based array)
                if(a[i] % 2 == 0) // This position has even number
                    evenHasEven = true;
                else // This position has odd number
                    evenHasOdd = true;
            }
        }

        // If both even and odd indices can have consistent parity, then we can make the whole array same parity
        if((oddHasEven && oddHasOdd) || (evenHasEven && evenHasOdd))
            return "NO";  // We have a mix of parities in one group that can't resolve
        else
            return "YES"; // We can align whole array to be either all odd or all even
    }
};


#endif