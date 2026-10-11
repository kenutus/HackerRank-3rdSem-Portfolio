/*
 * Problem : Diagonal Difference (HackerRank)
 * Topic   : 2D Arrays / Matrices
 *
 * Task: Given an N x N matrix, print the absolute difference between the
 *       sum of the primary diagonal and the sum of the secondary diagonal.
 *
 * Approach:
 *   Element (i, j) lies on the primary diagonal when j == i and on the
 *   secondary diagonal when j == N - 1 - i. We read the matrix row by row
 *   and add the matching element to each running sum as it arrives, so the
 *   matrix never has to be stored.
 *
 * Complexity:
 *   Time  : O(N^2) to read the input, but only O(N) diagonal work
 *           (one addition per row for each diagonal).
 *   Space : O(1) - two running sums, no matrix stored.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long primary = 0, secondary = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long value;
            cin >> value;
            if (j == i)         primary   += value;  // top-left to bottom-right
            if (j == n - 1 - i) secondary += value;  // top-right to bottom-left
        }
    }

    cout << llabs(primary - secondary) << '\n';
    return 0;
}
