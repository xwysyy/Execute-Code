#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {
        vector<int> results(q); 
        
        // Precompute the number of players at each position that will be eliminated
        vector<int> elim_track(max(n) + 1, 0); // Since n[i] can go up to max element in n
        
        for (int i = 0; i < k; ++i) {
            elim_track[a[i]]++;
        }
        
        // Precompute cumulative eliminations
        vector<int> cumulative_elim(max(n) + 1, 0);
        for (int i = 1; i <= max(n); ++i) {
            cumulative_elim[i] = cumulative_elim[i-1] + elim_track[i];
        }
        
        // Respond to each query
        for (int i = 0; i < q; ++i) {
            int num_players = n[i];
            // Calculate how many maintain throughout
            results[i] = num_players - cumulative_elim[num_players];
        }
        
        return results;
    }
};


#endif