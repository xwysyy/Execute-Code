#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, std::vector<int> &a) {
        // Step 1: Sort the array to facilitate optimal removals and conversions
        std::sort(a.begin(), a.end());
        
        // Step 2: Alice removes up to `k` smallest elements to maximize the sum
        int startIndex = std::min(k, n); // At most k elements
        a.erase(a.begin(), a.begin() + startIndex); // Erase up to `k` elements
        
        // Update `n` to reflect the new size of the array after deletions
        n = a.size();
        
        // Step 3: Sort again for Bob's turn
        std::sort(a.begin(), a.end());

        // Step 4: Bob converts up to `x` of the smallest (most negative) elements by multiplying them by -1
        for (int i = 0; i < x && i < n; ++i) {
            if (a[i] < 0) {
                a[i] = -a[i]; // Multiply by -1 to minimize sum
            } else {
                // If we reach a non-negative number, it's optimal to stop
                break;
            }
        }
        
        // Calculate and return the sum of the final array
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        return sum;
    }
};


#endif