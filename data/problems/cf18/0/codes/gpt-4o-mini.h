#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {   
        // Count the appearances of each number in the array using a map.
        unordered_map<int, int> countMap;
        for (int num : a) {
            if (num > 0) {
                countMap[num]++;
            }
        }

        // Now we will determine the distinct integers we need.
        long long cost = 0;
        int distinctNumbers = countMap.size(); // Number of distinct integers already present
        
        // The target number of distinct integers we ideally want in the final permutation
        int targetNumbers = distinctNumbers;

        while (true) {
            bool hasGaps = false; // to check if we have any gaps in numbers
            // Check if we have a permutation from 1 to targetNumbers.
            for (int i = 1; i <= targetNumbers; ++i) {
                if (countMap[i] == 0) { // If we lack i, we have a gap
                    hasGaps = true;
                    break;
                }
            }
            
            // If we do not have any gaps, we've formed a permutation successfully
            if (!hasGaps) {
                return cost; // Return the accumulated cost
            }

            // If we have gaps, we can either:
            // 1. Remove excess numbers (if any) based on their count
            // 2. Fill the gap by inserting numbers
            // Since we want to minimize the cost, we should decide whether to remove or add
            // We need to find the minimum cost approach
            
            // Determine excess elements and their cost to remove
            int excessCost = (n - distinctNumbers) * c;
            // Cost to insert a number into the gap
            int insertCost = d; 

            // Choosing the cheaper option to ensure we can fill the gaps
            if (insertCost <= excessCost) {
                // Can afford to fill gaps
                cost += insertCost;
                ++targetNumbers; // Increment the target size, as we fill a new number
            } else {
                // Remove an excess element per min cost
                cost += c;
                --n; // We decrement n, as we have one less element
                // We would ideally not consider this step, limit how much can be forced removal
            }
        }
    }
};


#endif