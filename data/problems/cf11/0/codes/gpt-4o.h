#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::vector<int> twos_count(n);
        int total_twos = 0;
        
        // Calculate current total number of twos in the product
        for (int i = 0; i < n; ++i) {
            int count = 0;
            int value = a[i];
            while (value % 2 == 0) {
                count++;
                value /= 2;
            }
            twos_count[i] = count;
            total_twos += count;
        }
        
        // If current number of twos >= n, no operations are needed
        if (total_twos >= n) {
            return 0;
        }

        // Calculate how many more twos are needed
        int more_twos_needed = n - total_twos;

        // Vector to hold how many additional twos each operation can add
        std::vector<int> additional_twos(n);
        
        // Calculate potential additional twos for each replacement operation a_i = a_i * i
        for (int i = 0; i < n; ++i) {
            int index = i + 1;  // converting to 1-based index
            int count = 0;
            while (index % 2 == 0) {
                count++;
                index /= 2;
            }
            additional_twos[i] = count;
        }
        
        // Sort additional_twos in descending order
        std::sort(additional_twos.begin(), additional_twos.end(), std::greater<int>());

        // Calculate minimum number of operations needed
        int operations = 0;
        for (int i = 0; i < n && more_twos_needed > 0; ++i) {
            more_twos_needed -= additional_twos[i];
            operations++;
        }
        
        // If we still need more twos after all operations, it's impossible
        if (more_twos_needed > 0) {
            return -1;
        }
        
        return operations;
    }
};


#endif