#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n) {
        int totalSum = 0; // This will hold the sum of digits of all numbers from 1 to n.

        for (int i = 1; i <= n; ++i) {
            totalSum += digitSum(i); // Calculate digit sum and add to total sum
        }

        return totalSum; // Return the total sum computed
    }
    
private:
    // A utility function to calculate the sum of digits of a given number
    int digitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10; // Add last digit
            number /= 10;       // Remove last digit
        }
        return sum;
    }
};


#endif