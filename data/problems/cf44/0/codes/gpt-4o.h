#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, std::vector<int> &a) {
        int rounds = 0;
        int start = 0;
        long long current_sum = 0;

        for (int end = 0; end < n; ++end) {
            current_sum += a[end];
            
            // Ensure the segment sum is within acceptable range
            while (current_sum > r) {
                current_sum -= a[start]; // Adjust by moving the start forward
                start++;
            }

            // Check if current sum of this segment is a winning round
            if (current_sum >= l && current_sum <= r) {
                // If we find a valid segment, we'll count it as a winning round
                rounds++;

                // Move start to potentially find a new segment
                current_sum -= a[start];
                start++;
            }
        }

        return rounds;
    }
};


#endif