#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {   
        int n = a.size();
        vector<int> maxOneA(n), maxOneB(n);
        vector<int> minOneA(n), minOneB(n);
        
        // Initialize maxOne and minOne arrays for both strings
        maxOneA[n-1] = (a[n-1] == '1' ? n-1 : -1);
        maxOneB[n-1] = (b[n-1] == '1' ? n-1 : -1);
        minOneA[0] = (a[0] == '1' ? 0 : n);
        minOneB[0] = (b[0] == '1' ? 0 : n);
        
        for(int i = n-2; i >= 0; --i) {
            maxOneA[i] = (a[i] == '1' ? i : maxOneA[i+1]);
            maxOneB[i] = (b[i] == '1' ? i : maxOneB[i+1]);
        }
        
        for(int i = 1; i < n; ++i) {
            minOneA[i] = (a[i] == '1' ? i : minOneA[i-1]);
            minOneB[i] = (b[i] == '1' ? i : minOneB[i-1]);
        }
        
        // Check if the transformation is possible
        for(int i = 0; i < n; ++i) {
            if(a[i] == '1') {
                if(minOneB[i] > i || maxOneB[i] < i) return "NO";
            }
            if(b[i] == '1') {
                if(minOneA[i] > i || maxOneA[i] < i) return "NO";
            }
        }
        
        return "YES";
    }
};


#endif