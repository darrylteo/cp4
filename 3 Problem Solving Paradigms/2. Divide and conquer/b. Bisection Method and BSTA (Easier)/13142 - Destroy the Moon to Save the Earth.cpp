#include <bits/stdc++.h>

using namespace std;

// what? just distance / time = speed (= mass to remove)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        double T, S, D;
        cin >> T >> S >> D;
        int x = D * 1e6 / (T * 24 * 60 * 60);
        if (x > 0)cout << "Remove " << x << " tons\n";
        else cout << "Add " << -x << " tons\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
