#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        multiset<int> bills;
        long long paid = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            for (int j = 0; j < x; ++j) {
                int y;
                cin >> y;
                bills.insert(y);
            }
            // standard way to get values from a set
            auto it = bills.begin();
            auto it2 = bills.end();
            --it2;
            paid += *it2 - *it;
            bills.erase(it);
            bills.erase(it2);
        }
        cout << paid << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

