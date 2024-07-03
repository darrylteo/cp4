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
    for (int cases = 1; cases <= T; ++cases) {
        string s;
        cin >> s;
        int n = s.size(), oddCnt = 0, ans = 0;
        int dat[26]{};
        for (int i = 0; i < n; i++) {
            memset(dat, 0, sizeof(dat));
            oddCnt = 0;
            for (int j = i; j < n; j++) {
                if (++dat[s[j] - 'a'] % 2) oddCnt++;
                else oddCnt--;
                if (oddCnt <= 1) ans++;
            }
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}