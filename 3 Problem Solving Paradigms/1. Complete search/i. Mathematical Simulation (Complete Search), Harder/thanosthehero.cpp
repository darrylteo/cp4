#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    reverse(a.begin(), a.end());
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        while (a[i] >= a[i - 1]) {
            a[i]--;
            ans++;
        }
        if (a[i] < 0) {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}