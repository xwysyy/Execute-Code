#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        // Initialize the number of vertices in the snowflake
        // starting with 1 initial vertex
        int vertices = 1; 
        int k = 2; // minimum k value as per problem constraints
        
        // Keep adding k vertices until we meet or exceed n
        while (vertices < n) {
            vertices += k; // Increment the total vertices by k
            k += 1; // Now for the next iteration, k increases by 1
        }
        
        // If we end up with exactly n vertices, return "YES"
        return (vertices == n) ? "YES" : "NO";
    }
};


#endif