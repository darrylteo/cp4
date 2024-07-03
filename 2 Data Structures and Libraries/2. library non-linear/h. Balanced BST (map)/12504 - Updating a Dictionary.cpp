#include <bits/stdc++.h>

using namespace std;

// each line 100 chars only so can just check O(n^2)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        map<string, string> mp1, mp2;
        string s1, s2;
        cin >> s1 >> s2;
        std::regex rgx("[,:{}]");
        std::sregex_token_iterator srti(s1.begin(), s1.end(), rgx, -1);
        std::vector<std::string> tokens;
        std::remove_copy_if(srti, std::sregex_token_iterator(),
                            std::back_inserter(tokens),
                            [](std::string const &s) { return s.empty(); });
        for (int i = 0; i < tokens.size(); i += 2) {
            mp1[tokens[i]] = tokens[i + 1];
        }
        srti = std::sregex_token_iterator(s2.begin(), s2.end(), rgx, -1);
        tokens.clear();
        std::remove_copy_if(srti, std::sregex_token_iterator(),
                            std::back_inserter(tokens),
                            [](std::string const &s) { return s.empty(); });
        for (int i = 0; i < tokens.size(); i += 2) {
            mp2[tokens[i]] = tokens[i + 1];
        }
        vector<string> new2, new1, changed;
        for (auto &i : mp2) {
            if (mp1.find(i.first) == mp1.end()) {
                new2.push_back(i.first); // not matched
            } else if (mp1[i.first] != i.second) {
                changed.push_back(i.first); // matched but diff value
            }
        }
        for (auto &i : mp1) {
            if (mp2.find(i.first) == mp2.end()) {
                new1.push_back(i.first); // not matched
            }
        }
        if (new1.empty() && new2.empty() && changed.empty()) {
            cout << "No changes" << endl;
        } else {
            if (!new2.empty()) {
                cout << "+";
                for (int i = 0; i < new2.size(); ++i) {
                    cout << new2[i];
                    if (i != new2.size() - 1) {
                        cout << ",";
                    }
                }
                cout << endl;
            }
            if (!new1.empty()) {
                cout << "-";
                for (int i = 0; i < new1.size(); ++i) {
                    cout << new1[i];
                    if (i != new1.size() - 1) {
                        cout << ",";
                    }
                }
                cout << endl;
            }
            if (!changed.empty()) {
                cout << "*";
                for (int i = 0; i < changed.size(); ++i) {
                    cout << changed[i];
                    if (i != changed.size() - 1) {
                        cout << ",";
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}