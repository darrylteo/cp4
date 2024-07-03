#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
ll memo[35];
vector<pair<string, int>> words;

ll dp(int i) {
    if (i == s.size()) return 1;
    if (memo[i] != -1) return memo[i];

    ll ans = 0;
    for (auto &word : words) {
        if (i + word.first.size() <= s.size() && s.substr(i, word.first.size()) == word.first) {
            ans += dp(i + word.first.size()) * word.second;
            ans %= 1000000007;
        }
    }

    return memo[i] = ans;
}

// should dp since have overlapping subproblems. for example hei+m and he+im and +ark already has been calculated

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n >> s;
    words.resize(n);
    for (auto &word : words) {
        cin >> word.first >> word.second;
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}