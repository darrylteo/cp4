#include <bits/stdc++.h>

using namespace std;

// sample gives hint of 2018^2 = 1118^2 + 1680^2

struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<pair<int, int>, pair_hash> s;
    int x, y, ans = 0;
    cin >> x;
    while (cin >> x >> y) {
        if (!s.empty()) {
            // list possible pairs
            vector<pair<int, int>> v;
            v.emplace_back(x + 2018, y);
            v.emplace_back(x - 2018, y);
            v.emplace_back(x, y + 2018);
            v.emplace_back(x, y - 2018);
            v.emplace_back(x + 1680, y + 1118);
            v.emplace_back(x + 1680, y - 1118);
            v.emplace_back(x - 1680, y + 1118);
            v.emplace_back(x - 1680, y - 1118);
            v.emplace_back(x + 1118, y + 1680);
            v.emplace_back(x + 1118, y - 1680);
            v.emplace_back(x - 1118, y + 1680);
            v.emplace_back(x - 1118, y - 1680);

            for (auto &q: v) {
                if (s.find(q) != s.end()) {
                    ans++;
                }
            }

        }
        s.insert({x, y});
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
