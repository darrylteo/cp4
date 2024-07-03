#include <bits/stdc++.h>

using namespace std;

// O(n^2) get all n^2 sums then compare closest another O(n^2)...

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, caseNum = 1;
    // use this for 10487 - Closest Sums 
    // while (cin >> n, n) {

    while (cin >> n) {
        cout << "Case " << caseNum++ << ":\n";
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<int> sums;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                sums.push_back(v[i] + v[j]);
            }
        }
        int m;
        cin >> m;
        while (m--) {
            int q;
            cin >> q;
            int closest = sums[0];
            for (int i = 1; i < sums.size(); ++i) {
                if (abs(q - sums[i]) < abs(q - closest)) {
                    closest = sums[i];
                }
            }
            cout << "Closest sum to " << q << " is " << closest << ".\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
