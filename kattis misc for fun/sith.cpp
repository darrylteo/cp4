#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    getline(cin, buf);
    int a, b;
    cin >> a >> b;
    if (a - b == abs(a - b)) {
        cout << "VEIT EKKI" << "\n";
    } else {
        int c;
        cin >> c;
        if (a - b == c) {
            cout << "JEDI" << "\n";
        } else {
            cout << "SITH" << "\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
