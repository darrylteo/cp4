#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005];
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

// direct code from book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    set<string> palindromes;
    while (cin >> s) {
        palindromes.clear();
        int n = (int) s.size();
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                memo[i][j] = -1;
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                if (isPalDP(i, j))
                    palindromes.insert(s.substr(i, j-i+1));
        for (const string &p : palindromes)
            cout << p << '\n';
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
