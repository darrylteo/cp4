#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<char, int> mp;
    mp['.'] = 20;
    mp['O'] = 10;
    mp['\\'] = 25;
    mp['/'] = 25;
    mp['A'] = 35;
    mp['^'] = 5;
    mp['v'] = 22;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            ans += mp[s[j]];
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
