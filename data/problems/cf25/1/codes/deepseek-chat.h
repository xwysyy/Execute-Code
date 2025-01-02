#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "YES"; // Only one vertex is always possible
        for (int k = 2; k <= 1000; ++k) {
            int total = 1; // Start with the initial vertex
            int level = 1;
            while (true) {
                int newVertices = k * level;
                total += newVertices;
                if (total == n) return "YES";
                if (total > n) break;
                level *= k;
            }
        }
        return "NO";
    }
};


#endif