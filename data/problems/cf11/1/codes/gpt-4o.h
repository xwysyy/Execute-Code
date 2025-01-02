#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int> &a) {   
        int initial_twos = 0;

        // Calculate the number of 2-factors in the original product
        for (int num : a) {
            while (num % 2 == 0) {
                initial_twos++;
                num /= 2;
            }
        }
        
        // If we already have enough 2's, no operation is needed
        if (initial_twos >= n) {
            return 0;
        }
        
        int deficit = n - initial_twos;
        vector<int> extra_twos(n);
        
        // Calculate how many extra 2's can each index provide
        for (int i = 1; i <= n; ++i) {
            int count = 0;
            int val = i;
            while (val % 2 == 0) {
                count++;
                val /= 2;
            }
            extra_twos[i - 1] = count;
        }

        // Sort the extra_twos in descending order to use the most beneficial indices first
        sort(extra_twos.rbegin(), extra_twos.rend());
        
        int total_extra_twos = 0;
        for (int i = 0; i < n; ++i) {
            // Accumulate extra_twos until the deficit is covered
            total_extra_twos += extra_twos[i];
            if (total_extra_twos >= deficit) {
                return i + 1; // Returning the count of operations required
            }
        }
        
        // If the loop finishes and we haven't reached the deficit, it's impossible
        return -1;
    }
};


#endif