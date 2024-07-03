#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// reverse of kattis - namethatpermutation
// for example abcd perm 10 (0 index) is bdac
// to get abcd from bdac, we know that perm/(length-1)! gives char index and perm%(length-1)! gives next perm
// to reverse, we have 1-2-0-0 from original [ORDER]
// build it backwards
// last letter c goes to idx 0. CURR = c
// next last letter a goes to idx 0. CURR = ac
// next last letter d goes to idx 2. CURR = acd
// next last letter b goes to idx 1. CURR = abcd

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> facts(21);
    facts[0] = 1;
    for (int i = 1; i <= 20; i++) {
        facts[i] = facts[i - 1] * i;
    }

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        string s;
        ull perm;
        cin >> s >> perm;
        --perm; // 0 index
        int n = (int) s.size();
        // get [ORDER]
        vector<ull> order(n);
        for (int i = 0; i < n; i++) {
            order[i] = perm / facts[s.size() - 1 - i];
            perm %= facts[s.size() - 1 - i];
        }

        string ans;
        for (int i = n - 1; i >= 0; i--) {
            ans.insert(ans.begin() + order[i], s[i]);
        }

        cout << "Case " << cases << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}