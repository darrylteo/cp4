#include <bits/stdc++.h>

using namespace std;

// check from current bird to next, how many extra birds can fit

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, d, n;
    cin >> l >> d >> n;
    vector<int> birds(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        birds[i] = x;
    }
    birds.push_back(l - 6 + d);
    birds.push_back(6 - d);
    sort(birds.begin(), birds.end());
    int ans = 0, curr = birds[0];
    for (int bird : birds) {
        if (bird - curr > d) {
            ans += (bird - curr) / d - 1; // this -1 cost alot of debug time !!
        }
        curr = bird;
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
