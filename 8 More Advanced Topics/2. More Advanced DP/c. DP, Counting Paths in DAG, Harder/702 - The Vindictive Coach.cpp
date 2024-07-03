#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// weird qn phrasing. the captain actually must be in front. can see from the sample output
// one of those hard but short qn.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll memo[25][25][2]{}; // num people to schedule, current height, next is shorter or taller (0 or 1)
    memo[0][1][0] = memo[0][1][1] = 1; // 0 left to schedule, current height is 1 since on 1 person only... height is 1
    for (int i = 1; i < 22; ++i) {
        for (int j = 1; j <= i + 1; ++j) { // e.g. if 10 guys left to schedule, current guy height range from 1-11
            for (int k = 1; k < j; ++k) {
                memo[i][j][0] += memo[i - 1][k][1]; // pick shorter guy next means taller guy now
            }
            for (int k = j; k <= i; ++k) { // 1 less guy possible (i+1)
                memo[i][j][1] += memo[i - 1][k][0];
            }
        }
    }
    int N, m;
    while (cin >> N >> m) {
        if (N <= 3) { // if capt 1: 123. if capt 2: 213. if capt 3: 312. cannot do otherwise. only 1 combo
            cout << 1 << '\n';
        } else if (m > 1) {
            cout << memo[N - 1][m][0] << endl;
        } else {
            cout << memo[N - 2][2][0] << endl; // start scheduling from 2nd guy i.e. 1-2-xxxxx
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
