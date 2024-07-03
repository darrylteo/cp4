#include <bits/stdc++.h>

using namespace std;

int T, n, m;
char c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> T;
    while (T--){
        cin >> c >> m >> n;
        if (c == 'r' || c == 'Q') cout << min(m, n) << endl;
        else if (c == 'k') cout << (m * n + 1) / 2 << endl;
        else cout << ((m + 1) / 2) * ((n + 1) / 2) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


