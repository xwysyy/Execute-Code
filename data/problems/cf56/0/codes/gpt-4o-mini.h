#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int useTimar = 0;
        int i = 0;

        while (i <= n - m) {
            // Check for a window of length m
            bool allWeak = true;

            for (int j = 0; j < m; j++) {
                if (s[i + j] == '1') {
                    allWeak = false;
                    break;
                }
            }

            // If we found a segment of m consecutive weak spots
            if (allWeak) {
                useTimar++; // Need to use Timar

                // Strengthen the segment of length k starting from index i
                // Move i to the next spot that will be out of this strengthened segment
                i += k; // Step to next potential weak segment after k length
            } else {
                // Move one position forward to check the next possible segment
                i++;
            }
        }

        return useTimar;
    }
};


#endif