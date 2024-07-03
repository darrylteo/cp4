#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[1000][27]; // memo[i][j] = minimum number of chunks after considering the first i segments ending with character c
vector<int> S;
int k;

ll dp(int i, int c) {
    if (i == S.size() / k) return 0; // no more chunks
    ll &ans = memo[i][c];
    if (ans != -1) return ans;

    set<int> curr;
    for (int j = i * k; j < (i + 1) * k; j++) {
        curr.insert(S[j]);
    }

    ans = 1e9;
    if (find(curr.begin(), curr.end(), c) != curr.end()) { // link to previous chunk
        curr.erase(c);
    }
    for (int x : curr) {
        ans = min(ans, dp(i + 1, x) + (ll) curr.size());
    }
    if (curr.empty()) {
        ans = min(ans, dp(i + 1, c));
    }

    return ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> k >> s;
        S.clear();
        memset(memo, -1, sizeof(memo));
        for (char c : s) {
            S.push_back(c - 'a');
        }
        cout << dp(0, 26) << '\n'; // start with any c that is not 0 - 25 else a starting chunk with 'a' will wrong count
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}