#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, std::string &s) {
        // This will store the minimum time to cross, initialized to a large number
        int maxDistanceToGreen = 0;

        // Traverse the string to find all positions where the current color matches
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                int distanceToNextGreen = 1;

                // Find the nearest 'g' from the position i
                while (s[(i + distanceToNextGreen) % n] != 'g') {
                    distanceToNextGreen++;
                }

                // We track the maximum time needed to encounter 'g' from one of the 'c' positions
                maxDistanceToGreen = std::max(maxDistanceToGreen, distanceToNextGreen);
            }
        }

        return maxDistanceToGreen;
    }
};


#endif