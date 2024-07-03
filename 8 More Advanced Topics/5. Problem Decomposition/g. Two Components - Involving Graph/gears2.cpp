#include <bits/stdc++.h>

using namespace std;

struct gear {
    int x, y, r;

    gear() = default;
};

bool touching(gear a, gear b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) == (a.r + b.r) * (a.r + b.r);
}

// don't bother about ratio. it is just ratio between A and B
// 1 for cw and 0 for ccw. -1 if not reached

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<gear> gears(N);
    for (int i = 0; i < N; i++) cin >> gears[i].x >> gears[i].y >> gears[i].r;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (touching(gears[i], gears[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> cw(N, -1);
    queue<int> q;
    q.push(0);
    cw[0] = 1; // A start cw
    int ok = 1;
    while (!q.empty() && ok) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (cw[v] == -1) {
                cw[v] = 1 - cw[u];
                q.push(v);
            }
            if (cw[v] == cw[u]) {
                ok = 0;
                break;
            }
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    if (cw[N - 1] == -1) {
        cout << 0 << endl;
        return 0;
    }

    int A = gears[0].r, B = gears[N - 1].r;
    int gcd = __gcd(A, B);
    A /= gcd;
    B /= gcd;
    if (cw[N - 1]) cout << B << " " << A << endl;
    else cout << B << " " << -A << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}