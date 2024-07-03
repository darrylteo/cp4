#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-15, INF = 1e15;
ll n, fixedCost;
struct tline { // dp[i] = min(dp[j] + fixedCost + (i - j)^2) for j < i
    ll m, c; // y = c + fixedCost + (x - m)^2. so dp[j] is c, same as book, but m is different.
    ld p; // x-intercept of the line
};
vector<tline> lines;

//c1 + (x - m1)^2 = c2 + (x - m2)^2
//c1 - c2 = x^2 - 2xm2 + m2^2 - x^2 + 2xm1 - m1^2
//x = (c1 - c2 - m2^2 + m1^2) / (2m1 - 2m2)
ld getX(ll m1, ll c1, ll m2, ll c2) {
    return (ld) (c1 - c2 - m2 * m2 + m1 * m1) / (2 * (m1 - m2));
}

void addLine(ll m, ll c) {
    ld p = -INF;
    while (!lines.empty()) {
        p = getX(m, c, lines.back().m, lines.back().c);
        if (p < lines.back().p - EPS) lines.pop_back();
        else break;
    }
    lines.push_back((tline) {m, c, p});
}

ll getBestYFaster(ll x) {
    static int k = 0;
    k = min(k, (int) lines.size() - 1);
    while (k + 1 < (int) lines.size() && lines[k + 1].p <= x + EPS) ++k;
    return lines[k].c + fixedCost + (x - lines[k].m) * (x - lines[k].m);
}

// not sure what's going on but can just apply the formula from book
// and we know that h(k) >= h(k + 1) and g(k) <= g(k + 1) so will have O(N) algorithm

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> fixedCost;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        addLine(x, ans); // m, c. m is position of next walkway, c is dp[j]
        ans = getBestYFaster(x);
    }
    cout << ans << "\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
