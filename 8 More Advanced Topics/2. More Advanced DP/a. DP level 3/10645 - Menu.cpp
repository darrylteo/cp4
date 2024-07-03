#include <bits/stdc++.h>

using namespace std;

struct dish {
    int c, b; // cost, benefit
};

struct soln {
    double b; // benefit
    int c; // cost

    soln(double b, int c) : b(b), c(c) {}

    soln() : b(0), c(0) {}

    bool operator<(const soln &s) const {
        if (b == s.b) return c > s.c; // smaller cost
        return b < s.b; // larger benefit
    }
};

int k, n, m;
soln memo[25][105][55][5]; // (days left, budget left, prev dish, prev dish cnt);
dish dishes[55];
vector<int> path;

soln dp(int d, int b, int p, int pc) {
    if (d == 0) return {0, 0};
    if (memo[d][b][p][pc].b != -1) return memo[d][b][p][pc];

    soln ans = {-1000000000, 1000000000};
    for (int i = 0; i < n; i++) {
        if (b - dishes[i].c >= 0) {
            if (p == i) {
                double val = 0;
                if (pc + 1 == 2) val = dishes[i].b / 2.0;
                ans = max(ans, {dp(d - 1, b - dishes[i].c, i, pc + 1).b + val,
                                dp(d - 1, b - dishes[i].c, i, pc + 1).c + dishes[i].c});
            } else {
                ans = max(ans, {dp(d - 1, b - dishes[i].c, i, 1).b + dishes[i].b,
                                dp(d - 1, b - dishes[i].c, i, 1).c + dishes[i].c});
            }
        }
    }

    return memo[d][b][p][pc] = ans;
}

void getPath(int d, int b, int p, int pc) {
    if (d == 0) return;
    soln ans = dp(d, b, p, pc);
    for (int i = 0; i < n; i++) {
        if (b - dishes[i].c >= 0) {
            if (p == i) {
                double val = 0;
                if (pc + 1 == 2) val = dishes[i].b / 2.0;
                if (ans.b == dp(d - 1, b - dishes[i].c, i, pc + 1).b + val &&
                    ans.c == dp(d - 1, b - dishes[i].c, i, pc + 1).c + dishes[i].c) {
                    path.push_back(i + 1);
                    getPath(d - 1, b - dishes[i].c, i, pc + 1);
                    return;
                }
            } else {
                if (ans.b == dp(d - 1, b - dishes[i].c, i, 1).b + dishes[i].b &&
                    ans.c == dp(d - 1, b - dishes[i].c, i, 1).c + dishes[i].c) {
                    path.push_back(i + 1);
                    getPath(d - 1, b - dishes[i].c, i, 1);
                    return;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> k >> n >> m, k) {
        for (int i = 0; i < 25; i++)
            for (int j = 0; j < 105; j++)
                for (int z = 0; z < 55; z++)
                    for (int l = 0; l < 5; l++) {
                        memo[i][j][z][l].b = -1;
                        memo[i][j][z][l].c = -1;
                    }

        for (int i = 0; i < n; i++) cin >> dishes[i].c >> dishes[i].b;
        double ans = dp(k, m, 52, 1).b;
        if (ans < 0) {
            cout << "0.0\n\n";
            continue;
        }
        cout << fixed << setprecision(1) << ans << "\n";
        path.clear();
        getPath(k, m, 52, 1);
        for (int i = 0; i < path.size(); i++) {
            if (i) cout << " ";
            cout << path[i];
        }
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


