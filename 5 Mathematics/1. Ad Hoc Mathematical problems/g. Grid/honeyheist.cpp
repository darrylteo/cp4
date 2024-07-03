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

    int R, n, A, B, K; // n for chew. since recycle code,
    cin >> R >> n >> A >> B >> K;
    int N = 2 * R - 1;
    // grid1 to draw honeycomb
    vvi grid1(N, vi(N, -1));
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

    // draw WAX cells + get start and end + clear walkable cells
    int startR, startC, endR, endC;
    vi waxCells(K);
    for (int i = 0; i < K; i++) cin >> waxCells[i];
    sort(waxCells.begin(), waxCells.end());
    int waxIdx = 0;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (grid1[j][k] == waxCells[waxIdx]) {
                grid1[j][k] = -1;
                waxIdx++;
            }
            if (grid1[j][k] == A) {
                startR = j;
                startC = k;
            }
            if (grid1[j][k] == B) {
                endR = j;
                endC = k;
            }
            if (grid1[j][k] != -1) {
                grid1[j][k] = 0;
            }
        }
    }

    // BFS from start
    vvi dist(N, vi(N, -1));
    queue<pair<int, int>> q;
    q.push({startR, startC});
    dist[startR][startC] = 0;
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int newR = r + dirR[i];
            int newC = c + dirC[i];
            if (newR >= 0 && newR < N && newC >= 0 && newC < N && grid1[newR][newC] == 0 && dist[newR][newC] == -1) {
                dist[newR][newC] = dist[r][c] + 1;
                q.push({newR, newC});
            }
        }
    }
    if (dist[endR][endC] > n || dist[endR][endC] == -1) {
        cout << "No" << endl;
    } else {
        cout << dist[endR][endC] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

