#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int currentFactorsOf2 = 0;
        
        // Count total factors of 2 already in the product
        for (int number : a) {
            while (number % 2 == 0) {
                currentFactorsOf2++;
                number /= 2;
            }
        }

        // We need at least n factors of 2
        int needed = n - currentFactorsOf2;

        // Count how many even indices we have (1-indexed)
        int possibleOperations = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0)
                possibleOperations++;
        }

        // If we need more factors of 2 than available transformations, return -1
        if (needed > possibleOperations) {
            return -1;
        }

        // Otherwise, the number of operations needed is exactly the number of additional factors of 2 needed
        return needed;
    }
};


#endif