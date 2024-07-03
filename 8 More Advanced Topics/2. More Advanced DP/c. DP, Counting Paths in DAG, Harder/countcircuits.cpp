#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
    int x, y;
};

ll memo[40][900][900]; // id, x, y
int n;
vector<point> points;

ll dp(int id, int x, int y) {
    if (id == n) {
        if (x == 450 && y == 450) return 1;
        return 0;
    }
    ll &ret = memo[id][x][y];
    if (ret != -1) return ret;
    ret = dp(id + 1, x + points[id].x, y + points[id].y) + dp(id + 1, x, y);
    return ret;
}

// start at (450, 450) and must end at (450, 450)
// kinda owo just a few mins can do a hard qn...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0, 450, 450) - 1 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
