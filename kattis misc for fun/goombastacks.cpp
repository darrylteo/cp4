#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pass = 1, stash = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        stash += x;
        cin >> x;
        if (stash < x) {
            pass = 0;
            break;
        }
    }
    if (!pass) cout << "impossible\n";
    else cout << "possible\n";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
