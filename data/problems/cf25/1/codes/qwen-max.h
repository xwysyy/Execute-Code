#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {   
        if (n == 1) return "NO";
        for (int k = 2; k <= 1000; ++k) {
            int total = 1 + k; // initial vertex + k new vertices
            int lastLayer = k;
            while (total < n) {
                int newVertices = lastLayer * (k - 1);
                if (total + newVertices > n) break;
                total += newVertices;
                lastLayer = newVertices;
            }
            if (total == n) return "YES";
        }
        return "NO";
    }
};

#endif