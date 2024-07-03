#include <bits/stdc++.h>

using namespace std;

// implement book idea of siamese method

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start = 1;
    while (cin >> n) {
        if (start == 0) cout << endl;
        start = 0;
        vector<vector<int>> a(n, vector<int>(n));
        int r = 0, c = n / 2, id = 1;
        while (a[r][c] == 0) {
            a[r][c] = id;
            if (id % n == 0) {
                r = (r + 1) % n;
            } else {
                r = (r - 1 + n) % n;
                c = (c + 1) % n;
            }
            id++;
        }
        int len = log10(n * n) + 1;

        int sum = 0;
        for (int i = 0; i < n; i++) sum += a[i][i];
        cout << "n=" << n << ", sum=" << sum << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ' ' << setw(len) << a[i][j];
            }
            cout << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
