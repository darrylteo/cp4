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
        int x;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x) {
                v.push_back(x);
            }
        }
        if (v.empty()) {
            cout << 0 << "\n";
        } else {
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i];
                if (i != v.size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
