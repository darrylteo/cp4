#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// reversed twice so easier to see when starting from largest power to lowest

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        if (n == -1 && k == -1) break;
        n++;
        vll a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        reverse(a.begin(), a.end());
        ll consta = a[n - 1];
        for (int i = 0; i < n - k; ++i) {
            a[i + k] -= a[i];
            a[i] = 0;
        }
        reverse(a.begin(), a.end());
        while (a.back() == 0) a.pop_back();
        for (int i = 0; i < a.size(); i++) {
            if (i != 0) cout << " " << a[i];
            else cout << a[i];
        }
        if (a.empty()) {
            cout << 0;
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

