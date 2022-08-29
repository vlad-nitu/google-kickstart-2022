//
// Created by Vlad Nitu on 29.08.2022.
//

#include "WiggleWalk.h"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int T, N, R, C, SR, SC;
string s;
unordered_map<char, pair<int, int>> map_command_to_coordinates{
        {'N', {-1,0}},
        {'E', {0,1}},
        {'S', {1, 0}},
        {'W', {0, -1}}
};

void solve_wiggle_walk() {

    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> R >> C >> SR >> SC;

        //https://stackoverflow.com/questions/13121469/initializing-a-vector-of-vectors-having-a-fixed-size-with-boost-assign
        vector<vector<bool>> grid( R + 1, vector<bool>(C+1)); // Initialise grid with R+1 rows and C+1 cols, grid[i][j] = false, for any i in (1, R) and j in (1,C)
        cin >> s;
        for (char cmd: s) {
            auto pair = map_command_to_coordinates[cmd];
            do {
                grid[SR][SC] = true; // Mark (SR,SC) as visited
                // GoTo next spot
                SR += pair.first;
                SC += pair.second;
            }while (grid[SR][SC]); //exec. cmd until we get on a spot that has not been visited before
        }

        cout << "Case #" << t << ": " << SR << " " << SC << '\n';
    }

    return;

}