#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            int sumOfDigits = 0;
            int number = i;

            // Calculate sum of digits of the number
            while (number > 0) {
                sumOfDigits += number % 10; // Add last digit
                number /= 10;                // Remove last digit
            }

            totalSum += sumOfDigits; // Add sum of digits to total sum
        }

        return totalSum;
    }
};


#endif