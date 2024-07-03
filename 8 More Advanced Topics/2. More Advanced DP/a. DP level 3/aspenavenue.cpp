#include <bits/stdc++.h>

using namespace std;

double memo[1005][1005]; // number of trees left to put on the left and right side of road
vector<double> v, b; // where the trees are at --- where the trees should be
int N, L, W;

double dp(int l, int r) {
    if (l == N / 2 && r == N / 2) return 0;
    if (memo[l][r] != -1) return memo[l][r];
    int curr = l + r; // current tree
    double ans = 1e9;
    if (l < N / 2) ans = min(ans, dp(l + 1, r) + abs(v[curr] - b[l])); // where it is - where it should be
    if (r < N / 2) ans = min(ans, dp(l, r + 1) + hypot(v[curr] - b[r], W));
    return memo[l][r] = ans;
}

// follow clue from book for quick solve =w=

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> N) {
        cin >> L >> W;
        v.resize(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < N / 2 + 1; i++) {
            for (int j = 0; j < N / 2 + 1; j++) {
                memo[i][j] = -1;
            }
        }
        b.clear();
        b.push_back(0);
        double curr = 0, spacing = L / (((double) N / 2) - 1);
        for (int i = 0; i < (N / 2) - 1; i++) {
            curr += spacing;
            b.push_back(curr);
        }
        cout << fixed << setprecision(10) << dp(0, 0) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


