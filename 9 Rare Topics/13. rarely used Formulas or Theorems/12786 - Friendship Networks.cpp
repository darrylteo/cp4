#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // everything below will be one based to match the book formula
    int n;
    while (cin >> n) {
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) cin >> d[i];
        sort(d.begin() + 1, d.end(), greater<int>());
        vector<int> cum(n + 1);
        cum[0] = 0;
        for (int i = 1; i <= n; i++) cum[i] = cum[i - 1] + d[i];
        if (cum[n] & 1) {
            cout << 0 << endl;
            continue;
        }

        int ok = 1;
        for (int k = 1; k <= n; k++) {
            int lhs = cum[k];
            int rhs = k * (k - 1);
            for (int i = k + 1; i <= n; i++) rhs += min(d[i], k);
            if (lhs > rhs) {
                ok = 0;
                break;
            }
        }
        cout << ok << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

