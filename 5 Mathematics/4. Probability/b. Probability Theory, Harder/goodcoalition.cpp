#include <bits/stdc++.h>

using namespace std;

double memo[155][155];
int n;
vector<pair<int, int>> parties;

// knapsack index, number of ppl chosen already. need 76
inline double dp(int idx, int num) {
    if (idx == n) {
        if (num >= 76) return 1;
        return 0;
    }
    if (num >= 76) return 1; // prevent out of bounds
    if (memo[idx][num] != -1) return memo[idx][num];
    return memo[idx][num] = max(dp(idx + 1, num + parties[idx].first) * parties[idx].second / 100, dp(idx + 1, num));
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        parties.clear();
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            parties.push_back({a, b});
        }
        for (int i = 0; i < 155; i++) for (int j = 0; j < 155; j++) memo[i][j] = -1;
        cout << fixed << setprecision(10) << (100 * dp(0, 0)) << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
