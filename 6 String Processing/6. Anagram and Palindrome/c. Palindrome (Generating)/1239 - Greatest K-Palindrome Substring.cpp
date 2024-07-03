#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005]; // initialize with -1
string s;

inline int isPalDP(int l, int r) { // number of changes to make s[l..r] palindrome
    if (l == r) return 0;
    if (l + 1 == r) return s[l] != s[r];
    int &ans = memo[l][r];
    if (ans != -1) return ans;
    ans = 0;
    if (s[l] == s[r]) {
        ans = isPalDP(l + 1, r - 1);
    } else {
        ans = 1 + isPalDP(l + 1, r - 1);
    }
    return ans;
}

// find the longest substring that has at most k changes

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> s >> k;
        memset(memo, -1, sizeof(memo));
        int n = s.size(), found = 0;
        for (int sz = n; sz >= 1; sz--) {
            if (found) break;
            for (int i = 0; i + sz <= n; i++) {
                if (isPalDP(i, i + sz - 1) <= k) {
                    cout << sz << '\n';
                    found = 1;
                    break;
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}