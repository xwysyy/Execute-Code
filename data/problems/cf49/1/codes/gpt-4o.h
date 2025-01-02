#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::string &s) {
        if (n == 0) return 0; // Edge case
        
        int operations = 0;
        
        // Step 1: If the length is odd, one delete operation is needed to make it even
        if (n % 2 != 0) {
            operations = 1;
            n--; // Pretend we deleted one character
        }
        
        std::map<char, int> evenFreq, oddFreq;
        
        // Step 2: Count frequencies of chars at even and odd indices
        for (int i = 0; i < n; i += 2) {
            evenFreq[s[i]]++;
        }
        for (int i = 1; i < n; i += 2) {
            oddFreq[s[i]]++;
        }
        
        // Step 3: Find the max frequency characters
        int maxEvenFreq = 0, maxOddFreq = 0;
        for (auto &[ch, freq] : evenFreq) {
            maxEvenFreq = std::max(maxEvenFreq, freq);
        }
        for (auto &[ch, freq] : oddFreq) {
            maxOddFreq = std::max(maxOddFreq, freq);
        }

        // Step 4: Calculate replacement operations required
        int evenChanges = (n / 2) - maxEvenFreq;
        int oddChanges = (n / 2) - maxOddFreq;
        
        operations += evenChanges + oddChanges;

        return operations;
    }
};


#endif