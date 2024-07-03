#include <bits/stdc++.h>

using namespace std;

// if not initially divisible by 3, see if there's a number to remove to make the sum divisible by 3. if not, S can't make a move and T wins
// else they alternately pick multiples of 3 and reduced to same as first game

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        string s;
        cin >> s;
        int n = s.size();
        int sum = 0, threeCnt = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i] - '0';
            if ((s[i] - '0') % 3 == 0) {
                threeCnt++;
            }
        }
        if (sum % 3 == 0) {
            if (threeCnt % 2) {
                cout << "Case " << cases << ": S" << endl;
            } else {
                cout << "Case " << cases << ": T" << endl;
            }
        } else {
            int found = 0;
            for (int i = 0; i < n; i++) {
                if ((sum - (s[i] - '0')) % 3 == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cout << "Case " << cases << ": T" << endl;
                continue;
            }
            if (threeCnt % 2) {
                cout << "Case " << cases << ": T" << endl;
            } else {
                cout << "Case " << cases << ": S" << endl;
            }
        }

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

