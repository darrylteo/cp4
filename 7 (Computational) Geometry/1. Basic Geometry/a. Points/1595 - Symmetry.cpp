#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> s(n);
        for (int i = 0; i < n; i++) cin >> s[i].first >> s[i].second;
        sort(s.begin(), s.end());
        sort(s.begin() + n / 2, s.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        int ok = 1;
        for (int i = 0; i < n / 2; i++) {
            // condition: check if the pairs on opposite sides are same height, IF they are not same x value. otherwise it's fine
            if (s[i].second != s[n - i - 1].second && s[i].first != s[n - i - 1].first) {
                ok = 0;
                break;
            }
        }
        // check if middle point balances the two sides
        double midX;
        if (n % 2 && n > 1) {
            midX = s[n / 2].first;
        } else {
            midX = (s[n / 2].first + s[n / 2 - 1].first) / 2.0;
        }
        for (int i = 0; i < n / 2; i++) {
            if (fabs((midX - s[i].first) - (s[n - i - 1].first - midX)) > 1e-9) {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}