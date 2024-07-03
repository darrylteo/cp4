#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, K, Q;

// depth of perfect k-ary tree
ll hsb(ll x) {
    return (ll) ceil(log((K - 1) * x + 1) / log(K) - 1);
}

// runs in O(log_K(N)). catch the corner case of K = 1
// similar to codeforces 1981C - Turtle and an Incomplete Sequence, LCA and binary lifting

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N >> K >> Q;
    while (Q--) {
        ll u, v;
        cin >> u >> v;
        if (K == 1) {
            cout << abs(u - v) << endl;
            continue;
        }
        int ans = 0;
        ll depthU = hsb(u), depthV = hsb(v);
        // see sample diagram. using the formula we can get the parent of a node.
        // e.g. 5/3=1 would be wrong but (5+3-2)/3=2 is correct
        // the "base case" is when K = 2 we normally just divide without the K-2 to get parent.
        // we make both u and v same level, then we keep going up until they meet.
        while (depthV > depthU) {
            v = (v + K - 2) / K;
            ans++;
            depthV--;
        }
        while (depthU > depthV) {
            u = (u + K - 2) / K;
            ans++;
            depthU--;
        }
        while (u != v) {
            v = (v + K - 2) / K;
            u = (u + K - 2) / K;
            ans += 2;
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}