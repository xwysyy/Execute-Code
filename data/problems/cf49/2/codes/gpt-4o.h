#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::string &s) {
        if (n == 1) {
            return 1; // only one character, can't form an even-length alternating string unless removed
        }
        
        // Count frequency of characters at even and odd indices
        std::unordered_map<char, int> evenFreq;
        std::unordered_map<char, int> oddFreq;
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                evenFreq[s[i]]++;
            } else {
                oddFreq[s[i]]++;
            }
        }
        
        // Maximum frequency of a single character at even and odd indices
        int maxEvenFreq = 0, maxOddFreq = 0;
        char maxEvenChar = s[0], maxOddChar = s[1];

        for (auto &entry : evenFreq) {
            if (entry.second > maxEvenFreq) {
                maxEvenFreq = entry.second;
                maxEvenChar = entry.first;
            }
        }

        for (auto &entry : oddFreq) {
            if (entry.second > maxOddFreq) {
                maxOddFreq = entry.second;
                maxOddChar = entry.first;
            }
        }

        if (n % 2 == 0) {
            // Min operations for even length string
            if (maxEvenChar != maxOddChar) {
                return (n / 2 - maxEvenFreq) + (n / 2 - maxOddFreq);
            } else {
                // Handle the case where max characters for even and odd are the same
                // Select the second best option to minimize replacements
                int secondMaxEvenFreq = 0, secondMaxOddFreq = 0;
                for (auto &entry : evenFreq) {
                    if (entry.first != maxEvenChar && entry.second > secondMaxEvenFreq) {
                        secondMaxEvenFreq = entry.second;
                    }
                }
                for (auto &entry : oddFreq) {
                    if (entry.first != maxOddChar && entry.second > secondMaxOddFreq) {
                        secondMaxOddFreq = entry.second;
                    }
                }

                return std::min((n / 2 - secondMaxEvenFreq) + (n / 2 - maxOddFreq),
                                (n / 2 - maxEvenFreq) + (n / 2 - secondMaxOddFreq));
            }
        } else {
            // Try deleting one character and check the minimal conversions required

            // Min operations without deletion
            int minOperations = (n / 2 - maxEvenFreq) + (n / 2 - maxOddFreq);

            // Try delete each index once
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    // Consider removing an even-indexed character temporarily
                    // Recalculate the max frequencies without this character
                    evenFreq[s[i]]--;
                    maxEvenFreq = 0;
                   

#endif