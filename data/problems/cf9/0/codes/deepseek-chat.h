#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> solve(int &n, int &q, vector<int> &a, vector<pair<int, int>> &queries) {
        vector<long long> result;
        long long sum = 0;
        for (int num : a) {
            sum += num;
        }
        
        for (auto &query : queries) {
            int type = query.first;
            int x = query.second;
            if (type == 0) {
                for (int &num : a) {
                    if (num % 2 == 0) {
                        num += x;
                        sum += x;
                    }
                }
            } else {
                for (int &num : a) {
                    if (num % 2 != 0) {
                        num += x;
                        sum += x;
                    }
                }
            }
            result.push_back(sum);
        }
        
        return result;
    }
};


#endif