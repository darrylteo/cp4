#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        vector<int> v;
        v.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            // range check. don't assign anything if out of bounds
            if (i + b < n && i + b >= 0) {
                v[i + b] = a;
            } else {}
        }
        // flag to check if all elements are assigned
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (v[i] == 0) {
                flag = false;
                break;
            }
        }
        // if ok, print result, else print -1
        if (flag) {
            for (int i = 0; i < n - 1; ++i) {
                cout << v[i] << " ";
            }
            cout << v[n-1] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}