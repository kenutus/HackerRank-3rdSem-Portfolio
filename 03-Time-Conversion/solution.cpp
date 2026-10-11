/*
 * Problem : Time Conversion (HackerRank)
 * Topic   : Strings & Logic
 *
 * Task: Convert a 12-hour time "hh:mm:ssAM" / "hh:mm:ssPM" to 24-hour
 *       (military) time "HH:mm:ss".
 *
 * Approach:
 *   Only the hour changes. Two edge cases matter:
 *     12:xx:xxAM -> 00:xx:xx   (midnight)
 *     12:xx:xxPM -> 12:xx:xx   (noon)
 *   Otherwise add 12 to the hour for PM and keep it for AM.
 *
 * Complexity:
 *   Time  : O(1) - the input always has exactly 10 characters.
 *   Space : O(1) - a fixed-size string.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int hour = stoi(s.substr(0, 2));
    string middle = s.substr(2, 6);   // ":mm:ss"
    bool isPM = (s[8] == 'P');

    if (isPM && hour != 12) hour += 12;  // 1 PM -> 13 ... 11 PM -> 23
    if (!isPM && hour == 12) hour = 0;   // 12 AM -> 00

    printf("%02d%s\n", hour, middle.c_str());
    return 0;
}
