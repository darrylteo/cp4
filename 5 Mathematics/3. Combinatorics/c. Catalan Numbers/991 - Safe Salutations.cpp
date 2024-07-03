#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> cat(22);
    cat[0] = 1;
    for (int i = 1; i <= 20; i++) {
        cat[i] = cat[i - 1] * (4 * i - 2) / (i + 1);
    }

    int n, start = 0;
    while (cin >> n) {
        if (start) cout << '\n';
        start = 1;
        cout << cat[n] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


