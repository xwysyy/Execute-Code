#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, string &s) {
        int returnable_rooms = 0;
        for (int start_room = 0; start_room < n; ++start_room) {
            bool can_return = false;
            for (int next_room = (start_room + 1) % n; next_room != start_room; next_room = (next_room + 1) % n) {
                bool can_reach = false;
                vector<int> visited(n, 0);
                queue<int> q;
                q.push(start_room);
                visited[start_room] = 1;
                while (!q.empty()) {
                    int current_room = q.front();
                    q.pop();
                    if (current_room == next_room) {
                        can_reach = true;
                        break;
                    }
                    int next1 = (current_room + 1) % n;
                    int prev1 = (current_room + n - 1) % n;
                    if (s[current_room] == '>' || s[current_room] == '-') {
                        if (!visited[next1]) {
                            visited[next1] = 1;
                            q.push(next1);
                        }
                    }
                    if (s[prev1] == '<' || s[prev1] == '-') {
                        if (!visited[prev1]) {
                            visited[prev1] = 1;
                            q.push(prev1);
                        }
                    }
                }

                if(can_reach){
                    vector<int> visited_back(n, 0);
                    queue<int> q_back;
                    q_back.push(next_room);
                    visited_back[next_room] = 1;
                    while(!q_back.empty()){
                        int current_room = q_back.front();
                        q_back.pop();

                        if(current_room == start_room){
                            can_return = true;
                            break;
                        }

                        int next1 = (current_room + 1) % n;
                        int prev1 = (current_room + n - 1) % n;
                        if (s[current_room] == '>' || s[current_room] == '-') {
                            if (!visited_back[next1]) {
                                visited_back[next1] = 1;
                                q_back.push(next1);
                            }
                        }
                        if (s[prev1] == '<' || s[prev1] == '-') {
                            if (!visited_back[prev1]) {
                                visited_back[prev1] = 1;
                                q_back.push(prev1);
                            }
                        }
                    }
                }
                if(can_return) break;
            }

            if (can_return) {
                returnable_rooms++;
            }
        }
        return returnable_rooms;
    }
};


#endif