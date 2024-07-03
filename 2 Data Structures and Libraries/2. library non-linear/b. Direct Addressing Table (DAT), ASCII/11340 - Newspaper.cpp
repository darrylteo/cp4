#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k;
        int charset[128] = {};
        cin >> k;
        char c;
        int x;
        while (k--) {
            cin >> c >> x;
            charset[c] = x;
        }
        int m;
        cin >> m;
        string line;
        cin.ignore();
        long long ans = 0;
        while (m--) {
            getline(cin, line);
            for (char ch : line) {
                if (ch>=0) { // there are out of bounds chars
                    ans += charset[ch];
                }
            }
        }
        cout << ans / 100 << "." << setw(2) << setfill('0') << ans % 100 << "$\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
