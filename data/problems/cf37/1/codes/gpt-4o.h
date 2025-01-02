#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int removals = 0;
        for (int i = 0; i < n; ) {
            if (i <= n - 3 && s.substr(i, 3) == "pie") {
                removals++;
                i += 3; // Skip 'pie' and move to the next potential starting point
            } else if (i <= n - 3 && s.substr(i, 3) == "map") {
                removals++;
                i += 3; // Skip 'map' and move to the next potential starting point
            } else {
                i++; // Move to the next character
            }
        }
        return removals;
    }
};


#endif