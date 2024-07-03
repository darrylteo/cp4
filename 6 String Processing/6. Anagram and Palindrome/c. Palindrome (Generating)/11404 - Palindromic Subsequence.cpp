#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005]; // initialize with -1
string s;

int isPalDP(int l, int r) { // number of chars to delete to make s[l..r] palindrome
    if (l == r) return 0;
    if (l + 1 == r) return s[l] != s[r];
    int &ans = memo[l][r];
    if (ans != -1) return ans;
    ans = 0;
    if (s[l] == s[r]) {
        ans = isPalDP(l + 1, r - 1);
    } else {
        ans = 1 + min(isPalDP(l + 1, r), isPalDP(l, r - 1));
    }
    return ans;
}

string pals[1005][1005];

string getPal(int l, int r) {
    if (l > r) return "";
    if (l == r) return string(1, s[l]);
    string ans = pals[l][r];
    if (!ans.empty()) return ans;
    ans = "";
    if (s[l] == s[r]) ans = s[l] + getPal(l + 1, r - 1) + s[r]; // didn't erase anything
    else if (isPalDP(l + 1, r) < isPalDP(l, r - 1)) ans = getPal(l + 1, r); // erased left
    else if (isPalDP(l + 1, r) > isPalDP(l, r - 1)) ans = getPal(l, r - 1); // erased right
    else ans = min(getPal(l, r - 1), getPal(l + 1, r)); // erased lexicographically larger
    return pals[l][r] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        memset(memo, -1, sizeof(memo));
        memset(pals, 0, sizeof(pals));
        int n = s.size();
        isPalDP(0, n - 1);
        cout << getPal(0, n - 1) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}