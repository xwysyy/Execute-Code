#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long initial_inversions = 0;
        long long max_inversions = 0;
        
        // Initial inversion count
        long long one_count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                one_count++;
            } else {
                initial_inversions += one_count;  // count inversions contributed by this 0
            }
        }
        
        max_inversions = initial_inversions;
        
        // Consider flipping each bit
        long long zero_before = 0; // Number of zeros handled till current position
        long long one_before = 0;  // Number of ones handled till current position

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                // Flipping current 0 to 1
                // It will remove all inversions counted with this zero
                // And add inversions with all 1s that come after this position
                long long zero_inversion = (one_before + 1);   // Adding new inversions
                long long one_inversion_remaining = (one_count - one_before); // Remaining 1's
                long long possible_inversion = initial_inversions + (one_inversion_remaining - zero_inversion);

                max_inversions = max(max_inversions, possible_inversion);
                zero_before++;  // We have another 0 before the ith index
            } else {
                // Flipping current 1 to 0
                // This will remove inversions of 1 contributed after it
                // And add inversions for all 0s that came before it
                long long one_inversion = (zero_before);   // Inversions with all 0s before
                long long zero_inversion_removed = (one_count - one_before - 1); // Remove own inversion
                long long possible_inversion = initial_inversions + (one_inversion - zero_inversion_removed);

                max_inversions = max(max_inversions, possible_inversion);
                one_before++;  // We have more 1s handled
            }
        }
        
        return max_inversions;
    }
};


#endif