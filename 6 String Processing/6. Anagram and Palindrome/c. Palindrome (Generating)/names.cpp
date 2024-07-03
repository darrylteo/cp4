#include <bits/stdc++.h>

using namespace std;

// worst case without adding is change 2nd half to match 1st half
// find anything better than this is improvement

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    s += string(n/2, '*'); // wildcard
    int lowest = INT_MAX;
    for (int sz = n; sz <= n + n/2; ++sz) {
        int cnt = 0;
        for (int i = 0; i < sz / 2; ++i) {
            if (s[i] != s[sz-1-i]) {
                cnt++;
            }
        }
        lowest = min(lowest, cnt);
    }
    cout << lowest << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}