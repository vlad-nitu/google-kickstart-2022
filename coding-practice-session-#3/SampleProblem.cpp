//
// Created by Vlad Nitu on 29.08.2022.
//

#include "SampleProblem.h"
#include <iostream>
#define NMAX 100001
using namespace std;
int T, N, M, C[NMAX], sum, x;

int solve_sample_problem() {

    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> M;
        sum = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> x;
            sum += x;
        }
        cout << "Case #" << t << ": " << sum % M << '\n';
    }


    return 0;
}
