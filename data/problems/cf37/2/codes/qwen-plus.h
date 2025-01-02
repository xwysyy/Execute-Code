#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {   
        int result = 0;
        vector<int> pieMatch(n, 0), mapMatch(n, 0);
        
        // Check for "pie" matches
        for (int i = 0; i < n; ++i) {
            if (i >= 1 && s[i] == 'e' && s[i-1] == 'i') pieMatch[i] = (i >= 2 && s[i-2] == 'p') ? 3 : 2;
            else if (i >= 0 && s[i] == 'i') pieMatch[i] = (i >= 1 && s[i-1] == 'p') ? 2 : 1;
            else if (s[i] == 'p') pieMatch[i] = 1;
        }
        
        // Check for "map" matches
        for (int i = 0; i < n; ++i) {
            if (i >= 2 && s[i] == 'p' && s[i-1] == 'a' && s[i-2] == 'm') mapMatch[i] = 3;
            else if (i >= 1 && s[i] == 'a' && s[i-1] == 'm') mapMatch[i] = 2;
            else if (s[i] == 'm') mapMatch[i] = 1;
        }
        
        // Calculate minimum deletions required
        int pieCount = 0, mapCount = 0;
        for (int i = 0; i < n; ++i) {
            if (pieMatch[i] == 3 || mapMatch[i] == 3) {
                result++;
                pieCount = 0;
                mapCount = 0;
            } else {
                if (pieMatch[i] > 0) pieCount = max(pieCount, pieMatch[i]);
                if (mapMatch[i] > 0) mapCount = max(mapCount, mapMatch[i]);
                if (pieCount == 3 || mapCount == 3) {
                    result++;
                    pieCount = 0;
                    mapCount = 0;
                }
            }
        }
        
        return result;
    }
};


#endif