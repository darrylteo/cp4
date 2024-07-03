#include <bits/stdc++.h>

using namespace std;

// Dilworth's theorem states that, in any finite partially ordered set, the largest antichain has the same size as the smallest chain decomposition. 
// Here, the size of the antichain is its number of elements, and the size of the chain decomposition is its number of chains.
// (note antichain is pair of elements that are not comparable ... so we can do sort increasing/decreasing and do LIS on first, or sort decreasing increasing and do LIS on second)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int k = 0;
        vector<int> L(n, 0);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        for (int i = 0; i < n; ++i) { // O(n log k)
            int pos = upper_bound(L.begin(), L.begin() + k, v[i].second) - L.begin();
            L[pos] = v[i].second; // greedily overwrite this
            if (pos == k) { // can extend LIS?
                k++; // k = longer LIS by +1
            }
        }
        cout << k << endl;

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
