#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Count initial number of factors of 2 in the product
        long long total_twos = 0;
        for (int x : a) {
            int count = 0;
            while (x % 2 == 0) {
                count++;
                x /= 2;
            }
            total_twos += count;
        }
        
        // We need 2^n factors of 2 in total
        long long needed_twos = n - total_twos;
        
        if (needed_twos <= 0) return 0;  // Already divisible by 2^n
        
        // Count how many factors of 2 we can get from each index
        vector<int> potential_twos;
        for (int i = 0; i < n; i++) {
            int idx = i + 1;  // 1-based index
            int count = 0;
            while (idx % 2 == 0) {
                count++;
                idx /= 2;
            }
            if (count > 0) {
                potential_twos.push_back(count);
            }
        }
        
        // Sort in descending order to get maximum twos with minimum operations
        sort(potential_twos.rbegin(), potential_twos.rend());
        
        int ops = 0;
        for (int twos : potential_twos) {
            if (needed_twos <= 0) break;
            needed_twos -= twos;
            ops++;
        }
        
        // If we still need more factors of 2, it's impossible
        return needed_twos <= 0 ? ops : -1;
    }
};


#endif