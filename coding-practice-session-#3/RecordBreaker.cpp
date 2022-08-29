//
// Created by Vlad Nitu on 29.08.2022.
//

#include "RecordBreaker.h"
#include <iostream>
#define NMAX 200003 //2*1e5+1
using namespace std;
int T, N, V[NMAX];
int solve_reacord_breaker() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> V[i];
        if (N == 1)
            cout << "Case #" << t << ": " << 1 << '\n';
        else {
            int Max = -1;
            int breaking_days = 0;
            for (int i = 0; i < N; ++i) {
                if (i == 0 && V[i] > V[i + 1])
                    breaking_days ++;
                else if (i == N - 1 && V[i] > Max)
                    breaking_days ++;
                else if (V[i] > Max && V[i] > V[i+1])
                    breaking_days ++;

                Max = max(Max, V[i]);
            }
            cout << "Case #" << t << ": " << breaking_days << '\n';
        }
    }
    return 0;
}
