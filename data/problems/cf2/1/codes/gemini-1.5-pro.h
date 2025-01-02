#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        int returnable_rooms = 0;
        for (int start_room = 0; start_room < n; ++start_room) {
            bool can_return = false;
            for (int direction = 0; direction < 2; ++direction) {
                int current_room = start_room;
                bool can_move = true;
                while (current_room != start_room || can_move) {
                    can_move = false;
                    int next_room = (current_room + (direction == 0 ? 1 : -1) + n) % n;
                    if (s[(current_room + n) % n] == '>' && direction == 0) {
                        current_room = next_room;
                        can_move = true;
                    } else if (s[(current_room + n) % n] == '<' && direction == 1) {
                        current_room = next_room;
                        can_move = true;
                    } else if (s[(current_room + n) % n] == '-') {
                        current_room = next_room;
                        can_move = true;
                    }
                     if (current_room == start_room && !can_move)
                         break;


                }
                if (current_room == start_room) {
                    can_return = true;
                    break;
                }
            }
            if (can_return) {
                returnable_rooms++;
            }
        }
        return returnable_rooms;
    }
};


#endif