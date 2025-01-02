#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "NO";  // A single node does not form a valid snowflake

        // Look for the smallest `k` such that the given vertices can be formed
        for (int k = 2; k * (k + 1) / 2 + 1 <= n; ++k) {
            int count = 1;
            int curLevelNodes = 1;

            // Simulate constructing the graph and count total vertices
            while (count < n) {
                curLevelNodes *= k;  // Each single-edge node expands by `k`
                count += curLevelNodes;
                if (count == n) return "YES";  // Exactly matches
            }
        }
        return "NO";
    }
};


#endif