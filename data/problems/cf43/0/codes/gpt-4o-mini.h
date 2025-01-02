#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array a
        sort(a.begin(), a.end());
        
        // Start checking from the end
        int max_possible = a[n - 1]; // Last element in the sorted array
        // Since we are allowed to choose any two indices, we focus on the largest
        // number and traverse backwards to check if we can reach this value.
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] >= max_possible) {
                max_possible = a[i]; // We can make all previous to this one the same
            } else {
                break;  // If we find a smaller number, we cannot increase beyond max_possible.
            }
        }
        
        return max_possible;
    }
};


#endif