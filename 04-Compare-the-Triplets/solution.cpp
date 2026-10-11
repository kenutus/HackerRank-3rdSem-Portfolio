/*
 * Problem : Compare the Triplets (HackerRank)
 * Topic   : Basic Implementation
 *
 * Task: Alice and Bob each get three ratings. For each position i, the
 *       person with the higher rating earns 1 point; ties earn nothing.
 *       Print "aliceScore bobScore".
 *
 * Approach:
 *   Read both triplets and compare element by element, keeping two
 *   counters.
 *
 * Complexity:
 *   Time  : O(1) - always exactly 3 comparisons.
 *   Space : O(1) - two arrays of size 3 and two counters.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3], b[3];
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];

    int alice = 0, bob = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i])      alice++;
        else if (a[i] < b[i]) bob++;
        // equal ratings: no points awarded
    }

    cout << alice << ' ' << bob << '\n';
    return 0;
}
