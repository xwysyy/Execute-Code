#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int num = i;
            int digitSum = 0;
            while (num > 0)
            {
                digitSum += num % 10;
                num /= 10;
            }
            sum += digitSum;
        }
        return sum;
    }
};


#endif