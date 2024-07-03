#include <bits/stdc++.h>

using namespace std;

// ref: https://github.com/frcepeda/Contest-Archive/blob/master/UVa/12155%20-%20ASCII%20Diamondi.cpp
// letter is manhattan dist from center. center is always 'a'

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1, N, row1, col1, row2, col2;
    while (cin >> N) {
        if (N == 0) break;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << "Case " << cases++ << ":\n";
        int sz = 2 * N - 1; // dimension of square grid
        for (int r = row1; r <= row2; ++r) {
            for (int c = col1; c <= col2; ++c) {
                int dist = abs(r % sz - N + 1) + abs(c % sz - N + 1); // use the example diagram to check (3,18)
                if (dist >= N) cout << '.';
                else cout << char('a' + dist % 26);
            }
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




