#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MOD 1000000007

ll parentCnt[105][10005]; // col, ribbon left
int visited[105][10005];

// DAG ~2x slower than dp.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c, r;
    cin >> n >> c >> r;
    if (c == 1) { // important. consider case 100 1 1. parent total on "last" column is 101, but only minus 2 flats
        cout << 0 << endl;
        return 0;
    }
    memset(parentCnt, 0, sizeof(parentCnt));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i <= n; i++) parentCnt[0][i] = 1;
    queue<ii> q;
    for (int i = 0; i <= r; i++) {
        if (n - i < 0) break;
        q.emplace(0, n - i); // use diff length of ribbon for 1st col
    }
    while (!q.empty()) {
        ii cur = q.front();
        q.pop();
        int col = cur.first, ribbonLeft = cur.second;
        if (visited[col][ribbonLeft]) continue;
        visited[col][ribbonLeft] = 1;
        if (col == c - 1) continue;
        for (int i = 0; i <= r; i++) {
            if (ribbonLeft - i < 0) break;
            parentCnt[col + 1][ribbonLeft - i] += parentCnt[col][ribbonLeft];
            parentCnt[col + 1][ribbonLeft - i] %= MOD;
            q.emplace(col + 1, ribbonLeft - i);
        }
    }

    // count total ways to go last column
    ll totalWays = 0;
    for (int i = 0; i <= n; i++) totalWays += parentCnt[c - 1][i];
    totalWays %= MOD;
    ll flatCnt = 0;
    for (int i = 0; i <= r; i++) if (n >= i * c) flatCnt++; // enough ribbon to make all height i
    cout << totalWays - flatCnt << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}