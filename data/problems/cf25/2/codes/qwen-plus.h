#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {   
        if (n == 1) return "YES"; // Only initial vertex

        for (int k = 2; k <= n; ++k) {
            int current = 1;
            int nextLevelVertices = k;
            while (current + nextLevelVertices <= n) {
                current += nextLevelVertices;
                if (current == n) return "YES";
                nextLevelVertices *= (k - 1);
                if (nextLevelVertices <= 0) break; // Avoid overflow and infinite loop
            }
        }

        return "NO";
    }
};


#endif