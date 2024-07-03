#include <bits/stdc++.h>

using namespace std;

// similar to 12747 - Back to Edit Distance

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, cases = 1;
    cin >> T;
    while (T--) {
        int n, p, q;
        cin >> n >> p >> q;
        p++, q++; // 1 based indexing
        vector<int> a(n * n + 1, -1), b(n * n + 1, -1);
        for (int i = 0; i < p; i++) {
            int x;
            cin >> x;
            a[x] = i; // a[k] tells the index of k in the array. e.g. a = 2 3 1. a[2] = 0
        }
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (a[x] == -1) continue; // if a[x] is -1, then it is not in the array a. so we ignore it.
            b[i] = a[x]; // b[i] tells the index of x in the array a. e.g. b = 3 2 1. a[3] = 1, b[0] = 1, b[1] = 0, b[2] = 2
        }
        // b is the important matrix. we can ignore a now.
        // we find longest increasing subsequence because if b increasing means it is same order as a
        // the non increasing ones will be removed/inserted
        vector<int> v;
        v.push_back(b[0]);
        for (int i = 1; i < b.size(); i++) {
            int pos = upper_bound(v.begin(), v.end(), b[i]) - v.begin();
            if (pos == v.size()) {
                v.push_back(b[i]);
            } else if (b[i] != -1) {
                v[pos] = b[i];
            }
        }
        cout << "Case " << cases++ << ": " << v.size() << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}