#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Function to count the number of trailing zeroes in binary representation
        auto countTrailingTwos = [](int x) {
            int count = 0;
            while (x % 2 == 0) {
                count++;
                x /= 2;
            }
            return count;
        };

        int totalTwos = 0;

        // Calculate current number of twos in the product
        for (int num : a) {
            totalTwos += countTrailingTwos(num);
        }

        // Calculate the deficiency (if any)
        int deficiency = n - totalTwos;

        if (deficiency <= 0) {
            // Already meets the requirement
            return 0;
        }

        // Now calculate the power of 2 for each index in 1 to n
        vector<int> powerOfTwoInIndex;
        for (int i = 1; i <= n; i++) {
            powerOfTwoInIndex.push_back(countTrailingTwos(i));
        }

        // Sort the powers in descending order
        sort(powerOfTwoInIndex.rbegin(), powerOfTwoInIndex.rend());

        // Use as few operations as possible to cover the deficiency
        int operations = 0;
        for (int t : powerOfTwoInIndex) {
            deficiency -= t;
            operations++;
            if (deficiency <= 0) {
                return operations;
            }
        }

        // If we've exhausted all indices without satisfying the condition
        return -1;
    }
};


#endif