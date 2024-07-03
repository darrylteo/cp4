#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// the eps is needed -_-

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vi v(n);
        double d;
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> d;
            v[i] = (int) (d * 100 + 1e-9);
            total += v[i];
        }
        int avg = total / n;
        int excess = total % n;
        int ans = 0;
        sort(v.begin(), v.end(), greater<int>());
        int i;
        for (i = 0; i < n; i++) {
            if (v[i] <= avg) break; // we are finding the rich ppl give the money to the poor
            ans += v[i] - avg - (excess-- > 0);
        }
        cout << "$" << fixed << setprecision(2) << ans / 100.0 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

