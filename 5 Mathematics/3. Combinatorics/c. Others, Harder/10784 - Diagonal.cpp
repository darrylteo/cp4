#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// n^2 - 3n - 2N >= 0
// n >= (3 + sqrt(9 + 8N)) / 2
// n = ceil((3 + sqrt(9 + 8N)) / 2)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull N, cases = 1;
    while (cin >> N, N) {
        ull n = (ceil) ((3.0 + sqrt(9 + 8 * N)) / 2);
        cout << "Case " << cases++ << ": " << n << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


