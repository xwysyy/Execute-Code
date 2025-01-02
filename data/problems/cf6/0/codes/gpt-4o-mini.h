#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        // Check the parity of the first element and the second element
        bool firstOdd = a[0] % 2 == 1; // Check if the first element is odd
        bool secondOdd = a[1] % 2 == 1; // Check if the second element is odd
        
        // If both have the same parity, we can make all elements the same parity
        if (firstOdd == secondOdd) {
            return "YES";
        }
        
        // If they have different parities, check the rest of the elements
        for (int i = 2; i < n; ++i) {
            // If indices are odd in range [2, n-1], they correspond to a[0] which is first
            // If indices are even in range [2, n-1], they correspond to a[1] which is second
            if (i % 2 == 0 && (a[i] % 2 == 1) != firstOdd) {
                return "NO";
            }
            if (i % 2 == 1 && (a[i] % 2 == 1) != secondOdd) {
                return "NO";
            }
        }
        
        return "YES"; // All elements can be made the same parity
    }
};


#endif