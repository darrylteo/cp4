#include <bits/stdc++.h>

using namespace std;

// similar to 644 - Immediate Decodability
// here we just check next since sorted
// tried sorting in uva 644 but it was slower than direct check. small n there

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        bool valid = true;
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == v[i + 1].substr(0, v[i].size())) {
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES\n" : "NO\n");
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

