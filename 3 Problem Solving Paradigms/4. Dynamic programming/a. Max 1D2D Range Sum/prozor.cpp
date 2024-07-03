#include <bits/stdc++.h>

using namespace std;

// not much value in doing cumsum since fixed size racket

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, S, K;
    cin >> R >> S >> K;
    vector<vector<char>> v(R, vector<char>(S));
    for (auto &i: v) {
        for (auto &j: i) {
            cin >> j;
        }
    }
    // start is inside the net (exclude the plus and minus sign in the picture)
    int bestCnt = 0, bestI = 0, bestJ = 0;
    for (int i = 1; i < R - K + 2; ++i) {
        for (int j = 1; j < S - K + 2; ++j) {
            int cnt = 0;
            for (int k = 0; k < K - 2; ++k) {
                for (int l = 0; l < K - 2; ++l) {
                    if (v[i + k][j + l] == '*') {
                        ++cnt;
                    }
                }
            }
            if (cnt > bestCnt) {
                bestCnt = cnt;
                bestI = i;
                bestJ = j;
            }
        }
    }
    v[bestI - 1][bestJ - 1] = '+';
    v[bestI - 1][bestJ + K - 2] = '+';
    v[bestI + K - 2][bestJ - 1] = '+';
    v[bestI + K - 2][bestJ + K - 2] = '+';
    for (int i = 0; i < K - 2; ++i) {
        v[bestI - 1][bestJ + i] = '-';
        v[bestI + K - 2][bestJ + i] = '-';
    }
    for (int i = 0; i < K - 2; ++i) {
        v[bestI + i][bestJ - 1] = '|';
        v[bestI + i][bestJ + K - 2] = '|';
    }
    cout << bestCnt << endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << v[i][j];
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
