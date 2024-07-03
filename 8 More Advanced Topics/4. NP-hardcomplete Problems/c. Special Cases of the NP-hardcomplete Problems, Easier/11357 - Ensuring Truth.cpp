#include <bits/stdc++.h>

using namespace std;

// huh... is just check between any pair of parentheses if term, and it's negation appears together right?

bool check(const string& s) {
    if (s.size() <= 2) return true; // either a or ~a
    int pos[26]{}, neg[26]{};
    istringstream iss(s);
    string term;
    while (getline(iss, term, '&')) {
        if (term.size() == 1) {
            if (neg[term[0] - 'a']) return false;
            pos[term[0] - 'a']++;
        }
        else {
            if (pos[term[1] - 'a']) return false;
            neg[term[1] - 'a']++;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s, curr;
        cin >> s;
        int open = 0, found = 0;
        for (char c: s) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                open--;
                if (check(curr)) {
                    cout << "YES\n";
                    found = 1;
                    break;
                }
                curr = "";
            } else {
                if (open) curr += c;
            }
        }
        if (!found) cout << "NO\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
