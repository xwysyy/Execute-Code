#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long currentInversions = 0;
        
        // Count initial inversions
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    currentInversions++;
                }
            }
        }
        
        long long maxInversions = currentInversions;

        // Evaluate the effect of flipping each bit
        for (int i = 0; i < n; ++i) {
            // Temporary variables to count new inversions
            long long change = 0;

            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    // We want to check the effect of flipping a[i]
                    // Original case
                    if (a[i] > a[j]) {
                        change -= 1; // this will reduce inversions
                    }
                    if (a[i] < a[j]) {
                        change += 1; // this will increase inversions
                    }
                }
            }
            
            // If we flip a[i]
            // We consider `1 - a[i]`
            // If a[i] is 1, it means it will be flipped to 0
            // If a[i] is 0, it means it will be flipped to 1
            
            if (a[i] == 1) {
                change -= 1; // flipping 1 to 0 reduces inversions with 1 after it
                change += (n - i - 1); // +1 for each 0 after it
            } else {
                change += 1; // flipping 0 to 1 increases inversions with 0 after it
                change -= i; // -1 for each 1 before it
            }

            maxInversions = max(maxInversions, currentInversions + change);
        }

        return maxInversions;
    }
};


#endif