#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct circle {
    ll x, y, r;
};

ll memo[1 << 15][15]; // unused, id. store best A

bool okCircle(circle &a, circle &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= (a.r + b.r) * (a.r + b.r);
}

int N;
vector<circle> circles;

ll dfs(int unused, int id) {
    if (memo[unused][id] != -1) return memo[unused][id];
    if (id == N) return 0;
    ll res = 0;
    res = max(res, dfs(unused, id + 1)); // skip this circle
    // compare to all used circles. if ok, try add this circle
    int ok = 1;
    for (int i = 0; i < N; i++) {
        if (unused & (1 << i)) continue;
        if (okCircle(circles[i], circles[id])) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        res = max(res, dfs(unused ^ (1 << id), id + 1) + circles[id].r * circles[id].r);
    }
    return memo[unused][id] = res;
}

// thinking about it, the problems are not overlapping...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        circles.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }
        memset(memo, -1, sizeof(memo));
        cout << dfs((1<<N)-1, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
