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
                bool moved = false;
                while (true) {
                    int next_room = -1;
                    if (direction == 0) { // Clockwise
                        next_room = (current_room + 1) % n;
                        if (s[current_room] == '<') {
                            next_room = -1;
                        }
                    } else { // Counter-clockwise
                        next_room = (current_room - 1 + n) % n;
                        if (s[(next_room)] == '>') {
                            next_room = -1;
                        }
                    }

                    if (next_room != -1) {
                        if (next_room == start_room) {
                            if (moved) {
                                can_return = true;
                                break;
                            }
                        } else {
                            moved = true;
                            current_room = next_room;
                        }

                    } else {
                       break;
                    }


                }
                if (can_return) break;
            }
            if (can_return) {
                returnable_rooms++;
            }
        }
        return returnable_rooms;
    }
};


#endif