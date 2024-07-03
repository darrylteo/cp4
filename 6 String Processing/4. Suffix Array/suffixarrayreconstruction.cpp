#include <bits/stdc++.h>

using namespace std;

// doesn't feel like suffix array question
// just fill the word from pos to end if no *
// else fill word from pos to * and from end to *

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int l, s;
        cin >> l >> s;
        vector<pair<int, string>> sufs(s, {0, ""});
        for (int i = 0; i < s; i++) {
            cin >> sufs[i].first >> sufs[i].second;
        }
        sort(sufs.begin(), sufs.end()); // put the largest string (smallest pos) first easier to find when it is wrong
        string word(l, '*');
        bool ok = true;
        for (auto &z: sufs) {
            if (!ok) break;
            int p = z.first;
            p--;
            string suf = z.second;
            bool star = false;
            // fill from p to p + suf.size() - 1
            for (int i = 0; i < suf.size(); i++) {
                if (suf[i] == '*') { // filled up to char before *, fill the rest in next loop
                    star = true;
                    break;
                } else if (word[p + i] == '*' || word[p + i] == suf[i]) {
                    word[p + i] = suf[i];
                } else {
                    ok = false;
                    break;
                }
            }
            // fill from back if star
            if (star) {
                int pos = l - 1;
                for (int i = suf.size() - 1; i >= 0; i--) {
                    if (suf[i] == '*') {
                        break;
                    } else if (word[pos] == '*' || word[pos] == suf[i]) {
                        word[pos] = suf[i];
                    } else {
                        ok = false;
                        break;
                    }
                    pos--;
                }
            }
        }
        // check if word is complete
        for (int i = 0; i < l; i++) {
            if (word[i] == '*') {
                ok = false;
                break;
            }
        }
        if (ok) cout << word << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}