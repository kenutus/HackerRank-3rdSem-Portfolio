/*
 * Problem : Sparse Arrays (HackerRank)
 * Topic   : Hash Maps / Strings
 *
 * Task: Given N input strings and Q query strings, print how many times
 *       each query string appears among the input strings.
 *
 * Approach:
 *   Naive: for every query, scan all N strings  -> O(N * Q).
 *   Better: build a frequency table once with an unordered_map
 *   (hash map), then answer each query with one average-O(1) lookup.
 *
 * Complexity (treating string length as bounded, as in the problem):
 *   Time  : O(N + Q) average - N insertions + Q lookups.
 *   Space : O(N) - at most N distinct keys in the map.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        freq[s]++;                      // count each input string
    }

    int q;
    cin >> q;
    while (q--) {
        string query;
        cin >> query;
        auto it = freq.find(query);     // find() avoids inserting new keys
        cout << (it == freq.end() ? 0 : it->second) << '\n';
    }
    return 0;
}
