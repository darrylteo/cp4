#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct shop {
    int cost, profit, net;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m, k;
        cin >> m >> k;
        vector<shop> shops(m);
        for (int j = 0; j < m; ++j) {
            cin >> shops[j].cost;
        }
        for (int j = 0; j < m; ++j) {
            cin >> shops[j].profit;
            shops[j].net = shops[j].profit - shops[j].cost;
        }
        sort(shops.begin(), shops.end(), [](shop a, shop b) {
            return a.net < b.net; // deny shop that has more negative net return 1st
        });
        ll ans = 0;
        for (int j = 0; j < m; ++j) {
            if (shops[j].net < 0) { // lose money, try to deny
                if (k > 0) { // deny
                    k--;
                } else { // lose money
                    ans += shops[j].net;
                }
            } else {
                ans += shops[j].net;
            }
        }
        cout << "Case " << i + 1 << ": ";
        if (ans > 0) cout << ans << endl;
        else cout << "No Profit" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

