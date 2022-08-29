//
// Created by Vlad Nitu on 29.08.2022.
//

#include "GBusCount.h"
#include <iostream>
#include <vector>
#define NMAX 5001
int T, N, P;
int left, right, city;


std::vector<int> constructDifferenceArray (std::vector<int> D) {
    std::vector<int> arr(NMAX);
    for (int i = 0; i < NMAX; ++i){
        if (i == 0)
            arr[i] = D[i];
        else
            arr[i] = arr[i-1] + D[i];
    }

    return arr;
}
// Difference Array (update in O(1) time) -> https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
void solve_gbus_count() {
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        std::cin >> N;
        std::vector<int> D(NMAX+1);

        for (int i = 0; i < N; ++i)
        {
            std::cin >> left >> right;
            D[left] ++;
            D[right + 1] --;
        }

        std::vector<int> solution = constructDifferenceArray(D);

        std::cin >> P;
        std::cout << "Case #" << t << ": ";
        for (int i = 0; i < P; ++i)
        {
           std::cin >> city;
           std::cout << solution[city] << ' ';
        }
        std::cout << '\n';


    }
    return;

}
