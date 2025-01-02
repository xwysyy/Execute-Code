#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {  
        int max_n = *max_element(n.begin(), n.end());
        vector<int> winners(max_n + 1, 0);

        // Process each winning count according to the sequence a
        for (int i = 1; i <= max_n; i++) {
            winners[i] = i;  // Start with all players as winners

            // Remove players according to given indices in a
            for (int j = 0; j < k; j++) {
                if (a[j] > winners[i]) {
                    break; // No more players can be kicked out
                }
                winners[i]--; // A player has been kicked out
            }
        }

        // Prepare result for queries
        vector<int> result;
        for (int i = 0; i < q; i++) {
            result.push_back(winners[n[i]]);
        }
        
        return result;
    }
};


#endif