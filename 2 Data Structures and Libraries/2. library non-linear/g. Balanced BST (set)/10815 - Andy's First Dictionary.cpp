#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    set<string> dict;
    while (getline(cin, buf)) {
        string word;
        for (char c : buf) {
            if (isalpha(c)) {
                word += tolower(c);
            } else {
                if (!word.empty()) {
                    dict.insert(word);
                    word.clear();
                }
            }
        }
        // last word
        if (!word.empty()) {
            dict.insert(word);
            word.clear();
        }
    }
    for (const string &word : dict) {
        cout << word << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

