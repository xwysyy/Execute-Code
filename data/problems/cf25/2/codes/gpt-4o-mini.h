#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        // A snowflake starts with 1 vertex and then every vertex that has degree 1 generates k new vertices.
        // If we denote the number of vertices at each generation:
        // Initial: 1 (the seed vertex)
        // After 1 generation with k new vertices: 1 + k
        // After 2 generations (for k again from the new leaf vertices): 1 + k + k*k (k vertices each connect to k new ones)
        // We can express the number of vertices as 1 + k + k^2 + ... + k^(m-1) for m generations.
        // Since we need to consider not just powers of k, we can derive a formula.
        
        // For a snowflake to exist, n = total vertices must be of the form:
        // n = 1 + k + k^2 + ... + k^m for some k >= 2 and m >= 1
        // This equals: n - 1 = k + k^2 + ... + k^m
        // The right side can be rewritten as a geometric series: n - 1 = k * (1 + k + k^2 + ... + k^(m-1)) = k * (k^m - 1) / (k - 1)
        
        // We observe that a valid n must be n = 1 + k(k^m - 1) / (k - 1) for integers k >= 2, m >= 1.
        // To simplify things further, we can use a more direct approach:
        
        // When n >= 3, it can be represented as a snowflake.
        // The only values for which a snowflake cannot exist are n = 1 and n = 2.
        // Therefore, we check for these cases.
        
        return (n >= 3) ? "YES" : "NO";
    }
};


#endif