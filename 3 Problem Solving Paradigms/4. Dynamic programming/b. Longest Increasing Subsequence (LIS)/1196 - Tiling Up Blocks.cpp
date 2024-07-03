#include <bits/stdc++.h>

using namespace std;

// easier version of kattis - nesteddolls

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {
        int k = 0;
        vector<int> L(n, 0);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) { // O(n log k)
            int pos = upper_bound(L.begin(), L.begin() + k, v[i].second) - L.begin(); // upper bound = increasing (not strictly)
            L[pos] = v[i].second; // greedily overwrite this
            if (pos == k) { // can extend LIS?
                k++; // k = longer LIS by +1
            }
        }
        cout << k << endl;
    }
    cout << "*" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
