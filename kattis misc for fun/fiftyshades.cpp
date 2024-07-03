#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, cnt = 0;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (char &c: s) {
            c = tolower(c);
        }
        if (s.find("pink") != string::npos || s.find("rose") != string::npos) {
            cnt++;
        }
    }
    if (cnt) cout << cnt << endl;
    else cout << "I must watch Star Wars with my daughter" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
