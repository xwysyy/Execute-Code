#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // Check how many segments of 'E' and if there's any 'N'
        bool hasN = false;
        int segmentCount = 0;
        bool inE = false; // Indicates whether we are within a segment of 'E'
        
        // Traverse the string to count segments
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'E') {
                if (!inE) {
                    inE = true;
                    segmentCount++; // Found a new segment of 'E'
                }
            } else {
                inE = false; // We've encountered an 'N'
                hasN = true; // We have at least one 'N'
            }
        }

        // Now, check for a contradiction:
        // If the string starts and ends with 'E's, they form one segment
        if (s[0] == 'E' && s[n - 1] == 'E') {
            segmentCount--; // We have one less segment due to the wrapping
        }

        // We can always place unique integers if the number of segments <= number of 'N's + 1
        if (hasN && segmentCount > 1) {
            return "NO"; // If we have multiple segments but only one 'N'
        }
        return "YES";
    }
};


#endif