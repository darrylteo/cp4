#include <bits/stdc++.h>

using namespace std;

// just naive search since grid small

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<vector<int>> v(501, vector<int>(501, 0));
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int j = x1; j < x2; j++) {
                for (int k = y1; k < y2; k++) {
                    v[j][k] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                cnt += v[i][j];
            }
        }
        cout << cnt << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}