#include <bits/stdc++.h>

using namespace std;

// need to choose a starting train. everything smaller than this goes in front (or behind)
// everything larger than this goes behind (or in front)
// if don't reverse, we cannot pick train i to be the starting train since everything in front already pass by
// we reverse to say we pick train i once it arrives, and queue all later trains accordingly
// pos is how many trains is it bigger than train i, posRev is how many trains is it smaller than train i
// add 1 cuz add itself

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> v, vRev;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
        vRev.push_back(-x);
    }
    reverse(v.begin(), v.end());
    reverse(vRev.begin(), vRev.end());
    vector<int> L(n, 0), LRev(n, 0);
    int k = 0, kRev = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, v[i]) - L.begin();
        L[pos] = v[i];
        if (pos == k) {
            ++k;
        }
        int posRev = lower_bound(LRev.begin(), LRev.begin() + kRev, vRev[i]) - LRev.begin();
        LRev[posRev] = vRev[i];
        if (posRev == kRev) {
            ++kRev;
        }
        ans = max(ans, pos + posRev + 1);
    }
    cout << ans << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
