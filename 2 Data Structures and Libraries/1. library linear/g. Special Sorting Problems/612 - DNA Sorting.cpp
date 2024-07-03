#include <bits/stdc++.h>

using namespace std;

struct DNA {
    string s;
    int inversions;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<DNA> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].s;
            v[i].inversions = 0;
            for (int j = 0; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    if (v[i].s[j] > v[i].s[k]) {
                        v[i].inversions++;
                    }
                }
            }
        }
        stable_sort(v.begin(), v.end(), [](DNA a, DNA b) {
            return a.inversions < b.inversions;
        });
        for (int i = 0; i < n; i++) {
            cout << v[i].s << endl;
        }
        if (T) {
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
