#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    int cnt1 = 0;
    for (char c: s1) {
        if (c == 'S') cnt1++;
    }
    int cnt2 = 0;
    for (char c: s2) {
        if (c == 'S') cnt2++;
    }
    if (cnt1 == 0 || cnt2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = cnt1 * cnt2;
    for (int i = 0; i < cnt; ++i) cout << "S(";
    cout << "0";
    for (int i = 0; i < cnt; ++i) cout << ")";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
