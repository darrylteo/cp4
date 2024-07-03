#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string forbidden;
    cin >> forbidden;
    string s;
    while (cin >> s) {
        bool ok = true;
        for (char c: forbidden) {
            if (s.find(c) != string::npos) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << s << ' ';
        } else {
            for (int i = 0; i < s.size(); i++) {
                cout << '*';
            }
            cout << ' ';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}