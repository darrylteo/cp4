#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    string awake(n, '0');
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            awake[i] = '1';
            if (i + 1 < n) {
                awake[i + 1] = '1';
            }
            if (i + 2 < n) {
                awake[i + 2] = '1';
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (awake[i] == '1') {
            ans++;
        }
    }
    cout << ans << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

