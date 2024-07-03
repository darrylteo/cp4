#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d, tmp;
    unordered_map<int, ull> m;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        m[tmp/d]++;
    }
    ull ans = 0;
    for (auto &i : m) {
        ans += (i.second * (i.second - 1)) / 2;
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


