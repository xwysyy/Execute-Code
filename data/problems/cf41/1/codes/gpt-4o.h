#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        // Sort the kick-out indices since the sequence a is guaranteed to be increasing
        sort(a.begin(), a.end());
        
        // Prepare an array to store number of winners for each possible starting player count
        int max_n = *max_element(n.begin(), n.end());
        vector<int> winners(max_n + 1);
        
        for (int p = 1; p <= max_n; ++p) {
            int remaining = p;  // Current players left
            int idx = 0;  // Current index in the a array
            
            // Reduce players until no kicks are possible
            while (idx < k && a[idx] <= remaining) {
                remaining--;  // Each valid a[idx] implies one less player remaining
                idx++;
            }
            
            winners[p] = remaining; // This many players win if we start with p players
        }
        
        // Prepare result for each query
        vector<int> result(q);
        for (int i = 0; i < q; ++i) {
            result[i] = winners[n[i]];
        }
        
        return result;
    }
};


#endif