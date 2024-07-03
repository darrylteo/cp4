#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0;
    vector<tuple<int,int,int>> v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x != -1) {
                v.emplace_back(i, j, x);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    for (auto &i : v) {
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
