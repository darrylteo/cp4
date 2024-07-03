#include <bits/stdc++.h>

using namespace std;

// he just walks to left and to right and back. park anywhere in between is ok

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
        for (int &i: a) cin >> i;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        cout << 2 * (a[n - 1] - a[0]) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
