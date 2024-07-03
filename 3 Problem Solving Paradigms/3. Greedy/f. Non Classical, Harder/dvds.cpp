#include <bits/stdc++.h>

using namespace std;

// just remove anything that isn't in the current order

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, curr = 1, x, shifts = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x == curr) {
                ++curr;
            } else {
                ++shifts;
            }
        }
        cout << shifts << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
