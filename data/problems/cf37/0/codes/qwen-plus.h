#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int removeCount = 0;
        bool inPie = false, inMap = false;

        for (int i = 0; i < n; ) {
            if (s.substr(i, 3) == "pie") {
                removeCount++;
                i += 3; // Skip "pie"
                inPie = true;
            } else if (s.substr(i, 3) == "map") {
                removeCount++;
                i += 3; // Skip "map"
                inMap = true;
            } else {
                i++;
            }

            // If both "pie" and "map" are found, we need to handle overlapping cases carefully
            if (inPie && inMap) {
                // Reset flags and recheck from the last position where one of the substrings started
                inPie = false;
                inMap = false;
                i -= 2; // Recheck previous two characters
            }
        }

        return removeCount;
    }
};


#endif