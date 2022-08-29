//
// Created by Vlad Nitu on 29.08.2022.
//
#include "SherlockAndWatsonGymSecrets.h"
#include <iostream>

#define NMAX 1001
#define ll long long
int T, A, B, N, K;
const ll MOD = 1e9 + 7 * (1000000007);

ll lg_pow(ll x, ll n) { //O(logN) time exponentiation -> https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/

    ll a;

    if (n == 0) return 1;

    if (n == 1) return x;

    a = lg_pow(x, n / 2); // x ^ (n // 2)

    if (n % 2 == 0) return (a * a) % K;

    else return ((x * a) % K * a) % K;

}

void solve_gym_secrets() { // O(N^2 log N) time, O(1) space
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {

        // Property: (i^A + i^B) mod K = (i^A mod K + i^B mod K) mod K
        std::cin >> A >> B >> N >> K;
        ll pairs = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (i != j) {
                    ll pow_i = lg_pow(i, A);
                    ll pow_j = lg_pow(j, B);
                    ll res = pow_i + pow_j;
                    if (res % K == 0)
                        pairs = (pairs + 1) % MOD;
                }
        std::cout << "Case #" << t << ": " << pairs << '\n';

    }

}


