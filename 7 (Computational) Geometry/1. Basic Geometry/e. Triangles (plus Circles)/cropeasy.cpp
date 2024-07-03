#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        ll n, A, B, C, D, x0, y0, M;
        cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
        vector<pair<ll, ll>> points;
        points.emplace_back(x0, y0);
        for (int i = 1; i < n; ++i) {
            ll x = (A * points[i - 1].first + B) % M;
            ll y = (C * points[i - 1].second + D) % M;
            points.emplace_back(x, y);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ll x1 = points[i].first, y1 = points[i].second;
                    ll x2 = points[j].first, y2 = points[j].second;
                    ll x3 = points[k].first, y3 = points[k].second;
                    if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
                        cnt++;
                    }
                }
            }
        }
        cout << "Case #" << cases << ": " << cnt << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}