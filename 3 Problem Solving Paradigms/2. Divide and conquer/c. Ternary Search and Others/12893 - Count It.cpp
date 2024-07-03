#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

ull backtrack(ull n) {
    if (n == 0) {
        return 0;
    }
    return backtrack(n / 2) + n % 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ull n;
        cin >> n;
        ull ans = backtrack(n);
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


