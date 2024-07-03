#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0, k = 0, T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s[0] == 'n') {
            n++;
        } else {
            k++;
        }
    }
    if (n && k) cout << "blandad best" << endl;
    else if (n) cout << "nautakjot" << endl;
    else cout << "kjuklingur" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}