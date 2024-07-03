#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// if largest and 2nd largest at sides, total water = 1 + 2 + ... + n - 2 = (n - 2) * (n - 1) / 2

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N, X;
    cin >> N >> X;
    if (X > (N - 1) * (N - 2) / 2) {
        cout << -1 << endl;
        return 0;
    }
    // using values from 1 to N - 2, find which to keep such that sum is X
    // print largest, all used stuff (any order), 2nd largest, remaining stuff (decreasing order)
    cout << N << " ";
    vector<bool> used(N, false);
    for (ll i = N - 2; i > 0; --i) {
        if (X >= i) {
            used[i] = true;
            X -= i;
            cout << N - 1 - i << " ";
        }
    }
    cout << N - 1 << " ";
    for (ll i = 1; i <= N - 2; ++i) {
        if (!used[i]) {
            cout << N - 1 - i << " ";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
