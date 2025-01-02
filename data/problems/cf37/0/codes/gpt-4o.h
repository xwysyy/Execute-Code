#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int removals = 0;
        
        for (int i = 0; i < n;) {
            // Check if "pie" appears starting from the current index
            if (i + 2 < n && s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') {
                removals++;
                i += 3;  // Move past this "pie"
            }
            // Check if "map" appears starting from the current index
            else if (i + 2 < n && s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p') {
                removals++;
                i += 3;  // Move past this "map"
            }
            else {
                i++;  // Increment normally if no substring found
            }
        }
        
        return removals;
    }
};


#endif