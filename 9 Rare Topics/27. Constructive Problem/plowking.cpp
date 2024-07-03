#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ref: https://github.com/mpfeifer1/Kattis/blob/master/plowking.py

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    ll ans = 0, nd = 2, wt = 1; // node, weight
    while (nd <= n) {
        ans += wt;
        m--; // use one edge
        wt++; // next edge weight
        ll waste = nd - 2; // bond to all previous nodes, except node 1
        ll need = n - nd; // save enough nodes for node 1 to remaining nodes
        waste = min(waste, m - need);
        m -= waste; // throw away waste edges
        wt += waste; // next will be this weight
        nd++;
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
