#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, std::vector<int> &a) {
        // Sort the array first
        std::sort(a.begin(), a.end());
        
        // Now decide on Alice's optimal strategy: removing up to k smallest (non-beneficial) elements
        // for maximizing the sum.
        int remove_count = std::min(k, static_cast<int>(a.size()));
        
        // Create a new array after Alice's optimal removal
        // Remove remove_count smallest elements, can't be more than k
        std::vector<int> remaining(a.begin() + remove_count, a.end());
        
        // Sort remaining to make it easier for Bob to choose largest positives to flip
        std::sort(remaining.begin(), remaining.end(), std::greater<int>());
        
        // Bob's optimal strategy: flipping x largest elements from positive to negative
        for (int i = 0; i < x && i < remaining.size(); ++i) {
            remaining[i] = -remaining[i];
        }
        
        // Calculate the resulting sum
        int resulting_sum = 0;
        for (const int &elem : remaining) {
            resulting_sum += elem;
        }
        
        return resulting_sum;
    }
};


#endif