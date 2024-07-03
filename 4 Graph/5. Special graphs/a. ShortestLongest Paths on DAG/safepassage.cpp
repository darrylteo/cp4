#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

// apparently a classic umbrella problem
// ref: https://www.cnblogs.com/zhien-aa/p/6295829.html

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0, i;
    // fastest L->R. fastest+slowest R->L. fastest L->R. fastest+slowest2 R->L
    // fastest L->R. slowest+slowest2 R->L. fastest2 L->R. fastest+fastest2 R->L
    for (i = n - 1; i > 2; i -= 2) {
        ans += min(v[0] + v[i] + v[0] + v[i - 1], v[0] + v[i] + v[1] + v[1]);
    }
    // handling how the fastest and fastest2 are at L
    if (i == 2) { // "start type 2" fastest+fastest2 R->L. fastest L->R. fastest+slowest R->L
        ans += v[1] + v[0] + v[2];
    } else if (i == 1) {
        ans += v[1]; // "start type 1" fastest+fastest2 R->L. first leg. since loop assumes fastest and fastest2 are at L
    } else {
        ans += v[0]; // in case only 1 student
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}