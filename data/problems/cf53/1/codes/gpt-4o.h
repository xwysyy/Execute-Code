#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return 0; // If there's only one student, disturbance is zero

        int initialDisturbance = 0;

        // Count initial disturbances
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                ++initialDisturbance;
            }
        }

        // Analyzing possible swap effects:
        // Find maximal instance of a single swap reducing the disturbance
        int currentDisturbance = initialDisturbance;
        for (int i = 0; i < n / 2; ++i) {
            // Try swapping `a[i]` with `a[n-i-1]` and simulate the effect
            if (a[i] == a[i + 1]) --currentDisturbance;  // If breaking consecutive identical
            if (a[n-i-2] == a[n-i-1]) --currentDisturbance;  // Similarly for right side

            if (a[i] == a[n-i-1]) ++currentDisturbance;  // If new pair created at swap 1
            if (i+1 < n && a[i+1] == a[n-i-1]) ++currentDisturbance; // New pair at left
            if (n-i-2 >= 0 && a[i] == a[n-i-2]) ++currentDisturbance; // New pair at right

            // Repositioned swap minimum of disturbance after individual swap
            initialDisturbance = min(initialDisturbance, currentDisturbance);

            // Undo temporaries if needed (for multiple streets and iterations)
        }

        return initialDisturbance;
    }
};


#endif