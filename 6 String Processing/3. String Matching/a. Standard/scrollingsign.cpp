#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int k, w;
        cin >> k >> w;
        string s;
        cin >> s;
        w--;
        string ans = s;
        while (w--) {
            cin >> s;
            int i = k;
            for (; i >= 0; --i) {
                if (ans.substr(ans.size() - i) == s.substr(0, i)) {
                    break;
                }
            }
            ans += s.substr(i);
        }
        cout << ans.size() << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


