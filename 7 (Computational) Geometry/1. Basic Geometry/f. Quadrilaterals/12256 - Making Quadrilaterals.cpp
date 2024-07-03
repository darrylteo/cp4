#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> v(61);
    v[1] = 1;
    v[2] = 1;
    v[3] = 1;
    for (int i = 4; i < 61; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }
    int n, cases = 1;
    while (cin >> n, n) {
        cout << "Case " << cases++ << ": " << v[n] << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}