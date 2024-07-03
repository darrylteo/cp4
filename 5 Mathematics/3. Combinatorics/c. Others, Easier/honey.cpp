#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// https://oeis.org/A002898

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> v(15);
    v[0] = 1;
    v[1] = 0;
    v[2] = 6;
    for (int i = 3; i < 15; i++) {
        v[i] = (36 * (i - 1) * (i - 2) * v[i - 3] + 24 * (i - 1) * (i - 1) * v[i - 2] + (i) * (i - 1) * v[i - 1]) / i / i;
    }

    int T;
    cin >> T;
    while (T--) {
        ull n;
        cin >> n;
        cout << v[n] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


