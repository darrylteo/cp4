#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, n;
    cin >> r >> n;
    vector<bool> x(r);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        x[a - 1] = true;
    }
    for (int i = 0; i < r; ++i) {
        if (!x[i]) {
            cout << i + 1 << ' ';
            return 0;
        }
    }
    cout << "too late" << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
