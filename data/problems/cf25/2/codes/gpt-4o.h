#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "NO"; // You cannot create a snowflake with only 1 vertex as it violates k > 1 rule.

        for (int k = 2; k <= n; ++k) {
            int vertices = 1;
            int factor = 1;

            // Check whether a geometric series with factor `k` can reach `n`
            while (vertices < n) {
                factor *= k;
                vertices += factor;
            }

            // If we find a k for which the vertices match exactly `n`, then it is a possible configuration
            if (vertices == n) return "YES";
        }
        return "NO";
    }
};


#endif