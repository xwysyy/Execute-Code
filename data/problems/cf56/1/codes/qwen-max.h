#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, string &s) {
        int timar Uses = 0;
        int i = 0;
        while (i < n) {
            // If we find a '0', it means we have found a weak spot
            if (s[i] == '0') {
                // Calculate the end of the segment to be strengthened
                int end = min(n, i + m - 1);
                // Strengthen the segment
                for (int j = i; j <= end; j += k) {
                    timarUses++;
                    for (int l = 0; l < k && j + l < n; ++l) {
                        s[j + l] = '1';
                    }
                }
                // Move to the end of the last strengthened segment
                i = end + 1;
            } else {
                i++;
            }
        }
        return timarUses;
    }
};

#endif