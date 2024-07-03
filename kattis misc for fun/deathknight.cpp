#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = n;
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == 'C' && s[i + 1] == 'D') {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}