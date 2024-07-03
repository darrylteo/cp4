#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vii rungs(m);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        rungs[i] = {x, x + 1};
    }

    // simulate
    vi ans(n + 1); // 1 based
    for (int i = 1; i <= n; i++) {
        int curr = i;
        for (int j = 0; j < m; j++) {
            if (rungs[j].first == curr) {
                curr = rungs[j].second;
            } else if (rungs[j].second == curr) {
                curr = rungs[j].first;
            }
        }
        ans[curr] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

