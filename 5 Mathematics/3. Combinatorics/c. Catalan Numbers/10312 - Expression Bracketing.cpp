#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull S(ull n) {
    if (n == 0 || n == 1 || n == 2) return 1;
    return (3 * (2 * n - 3) * S(n - 1) - (n - 3) * S(n - 2)) / n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> cat(27);
    cat[0] = 1;
    for (int i = 1; i <= 26; i++) {
        cat[i] = (2 * (2 * i - 1) * cat[i - 1]) / (i + 1);
    }

    ull n;
    while (cin >> n) {
        cout << S(n) - cat[n - 1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


