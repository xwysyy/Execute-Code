#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &a, int &b) {
        // Calculate the minimal number of steps using the alternation rule
        int dx = abs(a);
        int dy = abs(b);

        // The minimal time required is twice the maximum coordinate 
        // because the king cannot repeat the same move
        int answer = std::max(dx, dy) * 2;

        // If both dx and dy are odd, we need to add an extra move due to the alternation rule
        if ((dx % 2) != (dy % 2)) {
            answer++;
        }
        
        return answer;
    }
};


#endif