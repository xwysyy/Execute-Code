#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {   
        // Step 1: Sort the array
        std::sort(a.begin(), a.end());
        
        // Step 2: Return the second largest element
        // If n > 1, we simply take the (n-1)th element post sorting
        return a[n - 2]; // second last element
    }
};


#endif