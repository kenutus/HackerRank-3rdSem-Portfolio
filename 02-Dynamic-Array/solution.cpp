/*
 * Problem : Dynamic Array (HackerRank)
 * Topic   : Data Structures / Vectors
 *
 * Task: Keep N empty sequences and a variable lastAnswer = 0. Process Q
 *       queries:
 *         1 x y : idx = (x XOR lastAnswer) % N, append y to seq[idx]
 *         2 x y : idx = (x XOR lastAnswer) % N,
 *                 lastAnswer = seq[idx][y % size(seq[idx])], print it
 *
 * Approach:
 *   Store the sequences as a vector of vectors. push_back gives amortised
 *   O(1) appends and indexing is O(1), so every query is constant time.
 *
 * Complexity:
 *   Time  : O(N + Q) - O(N) to create the sequences, O(1) per query.
 *   Space : O(N + Q) - N sequence headers plus at most Q stored values
 *           (the activity sheet lists this as O(N)).
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> seq(n);
    int lastAnswer = 0;

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;

        int idx = (x ^ lastAnswer) % n;  // bitwise XOR picks the sequence

        if (type == 1) {
            seq[idx].push_back(y);
        } else {
            lastAnswer = seq[idx][y % seq[idx].size()];
            cout << lastAnswer << '\n';
        }
    }
    return 0;
}
