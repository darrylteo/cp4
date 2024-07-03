#include <bits/stdc++.h>

using namespace std;

// naive soln. works but slow.

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = i + 1;
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            int x;
            cin >> x;
            cout << a[x];
            a.erase(a.begin() + x);
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
