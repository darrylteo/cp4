#include <bits/stdc++.h>

using namespace std;

// smol. just brute force
// for each row, try all different column choices. since alice choice doesn't matter and just simulate all bob choice

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> perm(n);
        for (int i = 0; i < n; i++) {
            perm[i] = i;
        }
        int ans = INT_MAX;
        do {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i][perm[i]];
            }
            ans = min(ans, sum);
        } while (next_permutation(perm.begin(), perm.end()));
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
