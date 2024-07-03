#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;

const int dirR[] = {0, 1, 0, -1, -1, 1};
const int dirC[] = {1, 0, -1, 0, -1, 1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, K;
    cin >> R >> K;
    int N = 2 * R - 1;
    // grid1 to draw honeycomb, grid2 to store alice cells
    vvi grid1(N, vi(N, -1)), grid2(N, vi(N, 0));
    // draw honeycomb
    int idx = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R + i; j++) {
            grid1[i][j] = idx++;
        }
    }
    for (int i = R; i < N; i++) {
        for (int j = i - R + 1; j < N; j++) {
            grid1[i][j] = idx++;
        }
    }

    // draw alice cells
    vi aliceCells(K);
    for (int i = 0; i < K; i++) cin >> aliceCells[i];
    sort(aliceCells.begin(), aliceCells.end());
    int aliceIdx = 0;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (grid1[j][k] == aliceCells[aliceIdx]) {
                grid2[j][k] = 1;
                aliceIdx++;
            }
        }
    }

    // flood fill 4 sides
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        if (grid2[i][0] != 1) q.push({i, 0});
        if (grid2[i][N - 1] != 1) q.push({i, N - 1});
        if (grid2[0][i] != 1) q.push({0, i});
        if (grid2[N - 1][i] != 1) q.push({N - 1, i});
    }
    while (!q.empty()) {
        int j = q.front().first;
        int k = q.front().second;
        q.pop();
        if (grid2[j][k] == 2) continue;
        grid2[j][k] = 2;
        for (int i = 0; i < 6; i++) {
            int newJ = j + dirR[i];
            int newK = k + dirC[i];
            if (newJ >= 0 && newJ < N && newK >= 0 && newK < N && grid2[newJ][newK] == 0) {
                q.push({newJ, newK});
            }
        }
    }

    // from alice cells, for each dir, if touch outer flood or out of bounds, ans++
    int ans = 0;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (grid2[j][k] == 1) {
                for (int i = 0; i < 6; i++) {
                    int newJ = j + dirR[i];
                    int newK = k + dirC[i];
                    if ((newJ >= 0 && newJ < N && newK >= 0 && newK < N && grid2[newJ][newK] == 2)
                    || (newJ < 0 || newJ >= N || newK < 0 || newK >= N)) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

