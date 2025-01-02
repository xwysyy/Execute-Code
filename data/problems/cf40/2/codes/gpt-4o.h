#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.size();
        int maxLen = 0;
        
        // Iterate over all even possible lengths
        for (int len = 2; len <= n; len += 2) {
            for (int start = 0; start + len <= n; ++start) {
                int mid = start + len / 2;
                
                bool isTandem = true;
                for (int i = 0; i < len / 2; ++i) {
                    char firstHalf = s[start + i];
                    char secondHalf = s[mid + i];
                    
                    // They must either be equal or one must be a '?'
                    if (firstHalf != secondHalf && firstHalf != '?' && secondHalf != '?') {
                        isTandem = false;
                        break;
                    }
                }
                
                if (isTandem) {
                    maxLen = len;  // As the lengths are increasing, this will be the max found
                }
            }
        }
        
        return maxLen;
    }
};


#endif