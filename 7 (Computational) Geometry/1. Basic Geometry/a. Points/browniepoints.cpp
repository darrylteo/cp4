#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        int x = a[n / 2].first, y = a[n / 2].second;
        int s = 0, o = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].first == x || a[i].second == y) continue;
            if (a[i].first > x && a[i].second > y || a[i].first < x && a[i].second < y) s++;
            else o++;
        }
        cout << s << " " << o << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}