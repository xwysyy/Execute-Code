#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        // If the cost of removing an element is less than or equal to the cost of adding an element,
        // it is always better to remove all elements and then add a single 1.
        if (c <= d) {
            return 1LL * n * c + d;
        }
        
        // Otherwise, we need to find the longest subsequence that can be turned into a permutation
        // with the minimum number of insertions and deletions.
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end()); // Remove duplicates
        
        int max_perm_length = 0;
        for (int i = 0, j = 0; i < a.size(); ++i) {
            while (j < a.size() && a[j] - a[i] <= j - i) {
                ++j;
            }
            max_perm_length = max(max_perm_length, j - i);
        }
        
        // Calculate the number of deletions and insertions needed
        int deletions = n - max_perm_length;
        int insertions = max_perm_length - 1;
        
        // Return the total cost
        return 1LL * deletions * c + 1LL * insertions * d;
    }
};

#endif