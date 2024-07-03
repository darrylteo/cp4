#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;

// idk why this qn is rated easy. maybe just cuz it is small input then ppl also do this manual way
// y = x^6 - 20x^5 + 4x^4 + 30x^3 + 0x^2 - x + 2
// x = 0, y = 2, C0 = 2
// x = 1, y = 16, C1 = 16 - 2 = 14
// x = 2, y = -272, C2 = -272 - 2*14 - 2 = -302
// x = 3, y = -2998, C3 = -2998 + 3*302 - 3*14 - 2 = -2136
// x = 4, y = -13442, C4 = -13442 + 4*2136 + 6*302 - 4*14 - 2 = -3144
// x = 5, y = -40628, C5 = -40628 + 5*3144 + 10*2136 + 10*302 - 5*14 - 2 = -600
// x = 6, y = -97204, C6 = -97204 + 6*600 + 15*3144 + 20*2136 + 15*302 - 6*14 - 2 = 720

int yVal(int x, vi &coefs) {
    int y = 0;
    for (int i = 0; i < coefs.size(); ++i) {
        y += coefs[i] * pow(x, coefs.size() - i - 1);
    }
    return y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    n++;
    vi v(n), ans(n);
    vvi bino;
    bino.push_back({1, 2, 1});
    bino.push_back({1, 3, 3, 1});
    bino.push_back({1, 4, 6, 4, 1});
    bino.push_back({1, 5, 10, 10, 5, 1});
    bino.push_back({1, 6, 15, 20, 15, 6, 1});
    for (int i = 0; i < n; ++i) cin >> v[i];
    ans[0] = v[n-1];
    ans[1] = yVal(1, v) - ans[0];
    for (int i = 2; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += bino[i-2][j] * ans[j];
        }
        ans[i] = yVal(i, v) - sum;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

