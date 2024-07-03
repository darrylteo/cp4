#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int wonderful = 1;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i: v) {
            int ans = 0;
            for (char c: s) {
                ans = (ans * 10 + (c - '0')) % i;
            }
            if (ans) {
                wonderful = 0;
                break;
            }
        }
        cout << s << (wonderful ? " - Wonderful." : " - Simple.") << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


