#include <bits/stdc++.h>

using namespace std;

// man... not entry level because of printing :(

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, m, k;
    cin >> T;
    while (T--) {
        cin >> m >> k;
        vector<int> books(m);
        for (int i = 0; i < m; i++) cin >> books[i];
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int i = 0;
            for (int j = 0; j < k; j++) { // for each scribe
                int sum = 0;
                while (i < m && sum + books[i] <= mid) {
                    sum += books[i];
                    i++;
                }
                if (i == m) break;
            }
            if (i == m) r = mid; // reduce max pages
            else l = mid + 1;
        }

        int i = m - 1;
        vector<vector<int>> ans(k);
        for (int j = k - 1; j >= 0; j--) {
            int sum = 0;
            while (i >= 0 && sum + books[i] <= l && i >= j) { // i>=j means books remaining >= scribes remaining
                sum += books[i];
                ans[j].push_back(books[i]);
                i--;
            }
        }
        for (int j = 0; j < k; j++) {
            for (int x = ans[j].size() - 1; x >= 0; x--) {
                cout << ans[j][x];
                if (x > 0) cout << " ";
            }
            if (j < k - 1) cout << " / ";
        }
        cout << endl;
    }
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}