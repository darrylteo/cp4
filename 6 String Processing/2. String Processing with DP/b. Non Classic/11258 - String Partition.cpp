#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[205];
string s;

inline ll dp(int i) {
    if (i == s.size()) return 0;
    if (memo[i] != -1) return memo[i];

    ll ans = 0;
    for (int j = i; j < s.size(); j++) {
        string curr = s.substr(i, j - i + 1);
        if (curr.size() > 1 && curr[0] == '0') break; // no leading zeros
        ll num = stoll(curr);
        if (num > INT_MAX) break; // must be signed int
        ans = max(ans, num + dp(j + 1));
    }

    return memo[i] = ans;
}

// should dp since have overlapping subproblems. for example 111xxxx could be split as 11 1 xxxx or 1 11 xxxx with sum 12 for first part

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        memset(memo, -1, sizeof(memo));
        cout << dp(0) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}