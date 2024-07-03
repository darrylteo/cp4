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

    int n;
    while (cin >> n) {
        if (n == 1) cout << 1 << '\n';
        else cout << lower_bound(cat.begin(), cat.end(), n) - cat.begin() << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


