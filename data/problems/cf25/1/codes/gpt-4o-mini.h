#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {   
        // A snowflake can be represented as a type of tree structure where the first vertex is connected
        // to k leaf nodes (where k > 1), and each leaf can further become a parent of k new vertices
        // Therefore the total number of vertices in a valid snowflake can be constructed as follows:
        // Initial vertex + k vertices + k*new_children, each leaf can produce its own children.
        
        // The total number of vertices can be represented by the formula:
        // n = 1 + k + k^2 + ... + k^d, where d is the depth (number of levels)
        // This forms a geometric series:
        // n = (k^(d+1) - 1) / (k - 1)
        
        // For n to be a valid snowflake's vertex count, it can be deduced that n has to be in 
        // the form of 1 + k*(1 + k + k^2 + ...) => This implies that n - 1 must be divisible by k - 1.
        
        // We know:
        // For k = 2, observation shows that valid n are 1, 3, 7, 15, 31... (1 + 2^1 + 2^2 + ...)
        // 
        // For general k, we will check:
        
        if (n == 1) return "YES"; // Single vertex case

        for (int k = 2; k <= n; ++k) { // Try all k from 2 upwards
            int total = (1 - (int)pow(k, 0)) / (1 - k);
            while (total < n) {
                total += (int)pow(k, ++d);
            }
            if (total == n) return "YES";
        }

        return "NO";
    }
};


#endif