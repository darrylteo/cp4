#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        bool found = false;

        // check if OK first before checking mispellings
        for (const string &word: dict) {
            if (word == s) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << s << " is correct\n";
            continue;
        }

        // check for mispellings
        bool found1 = false, found2 = false, found3 = false, found4 = false;
        for (const string &word: dict) {

            // missing 1 letter
            if (word.size() == s.size() + 1) {
                for (int i = 0; i < word.size(); i++) {
                    string t = word;
                    t.erase(i, 1);
                    if (t == s) {
                        cout << s << " is a misspelling of " << word << '\n';
                        found1 = true;
                        break;
                    }
                }
            }
            if (found1) break;

            // extra 1 letter
            if (word.size() == s.size() - 1) {
                for (int i = 0; i < s.size(); i++) {
                    string t = s;
                    t.erase(i, 1);
                    if (t == word) {
                        cout << s << " is a misspelling of " << word << '\n';
                        found2 = true;
                        break;
                    }
                }
            }
            if (found2) break;

            // wrong letter (optional to check all letters one by one or the first wrong letter only... short strings so both ok)
            if (word.size() == s.size()) {
                for (int i = 0; i < s.size(); i++) {
                    string t = s;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == s[i]) continue;
                        t[i] = c;
                        if (t == word) {
                            cout << s << " is a misspelling of " << word << '\n';
                            found3 = true;
                            break;
                        }
                    }
                    if (found3) break;
                }
            }
            if (found3) break;

            // swap adjacent letters
            if (word.size() == s.size()) {
                for (int i = 0; i < s.size() - 1; i++) {
                    string t = s;
                    swap(t[i], t[i + 1]);
                    if (t == word) {
                        cout << s << " is a misspelling of " << word << '\n';
                        found4 = true;
                        break;
                    }
                }
            }
            if (found4) break;
        }

        if (!found1 && !found2 && !found3 && !found4) {
            cout << s << " is unknown\n";
        }

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

