#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 1) return 1; // If the length is 1, we need to delete the only character.
        
        // Counters for the most common characters in even and odd positions
        vector<int> evenCount(26, 0), oddCount(26, 0);
        char mostCommonEven = s[0], mostCommonOdd = s[1];
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenCount[s[i] - 'a']++;
                if (evenCount[s[i] - 'a'] > evenCount[mostCommonEven - 'a']) {
                    mostCommonEven = s[i];
                }
            } else {
                oddCount[s[i] - 'a']++;
                if (oddCount[s[i] - 'a'] > oddCount[mostCommonOdd - 'a']) {
                    mostCommonOdd = s[i];
                }
            }
        }
        
        // Calculate the number of changes needed if we don't delete any character
        int changesWithoutDelete = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s[i] != mostCommonEven) changesWithoutDelete++;
            if (i % 2 == 1 && s[i] != mostCommonOdd) changesWithoutDelete++;
        }
        
        // If the most common characters in even and odd positions are the same, we need to consider deleting one character
        if (mostCommonEven == mostCommonOdd) {
            int changesWithDelete = n;
            for (int i = 0; i < n; i++) {
                int tempChanges = 0;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        if (j % 2 == 0 && s[j] != mostCommonEven) tempChanges++;
                        if (j % 2 == 1 && s[j] != mostCommonOdd) tempChanges++;
                    }
                }
                changesWithDelete = min(changesWithDelete, tempChanges + 1);
            }
            return min(changesWithoutDelete, changesWithDelete);
        }
        
        return changesWithoutDelete;
    }
};

#endif