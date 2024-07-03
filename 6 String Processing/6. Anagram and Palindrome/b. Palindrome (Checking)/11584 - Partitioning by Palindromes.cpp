#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005], memo2[1005];
string s;

inline int isPalDP(int l, int r) { // is s[l..r] a palindrome
    if (l == r) return 1; // one character
    if (l+1 == r) return s[l] == s[r]; // two characters
    int &ans = memo[l][r];
    if (ans != -1) return ans; // has been computed
    ans = 0;
    if (s[l] == s[r]) ans = isPalDP(l+1, r-1); // if true, recurse inside
    return ans;
}

inline int minCutDP(int l) {
    if (l == (int) s.size()) return 0; // done
    int &ans = memo2[l];
    if (ans != -1) return ans; // has been computed
    ans = 1e9;
    for (int i = l; i < (int) s.size(); ++i)
        if (isPalDP(l, i)) // if s[l..i] is a palindrome
            ans = min(ans, 1 + minCutDP(i+1)); // cut here
    return ans;
}

// direct code from book

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
        int n = (int) s.size();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                memo[i][j] = -1;
        for (int i = 0; i < n; ++i)
            memo2[i] = -1;
        cout << minCutDP(0) << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
