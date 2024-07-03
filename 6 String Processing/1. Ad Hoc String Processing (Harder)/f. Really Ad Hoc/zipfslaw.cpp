#include <bits/stdc++.h>

using namespace std;

// A word is a sequence of letters. Words are separated by non-letters. Capitalization should be ignored.
// unsure why qn is classified as 6.0 hard. it's similar to previous 2.0 easy problems

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start = 1;
    while (cin >> n >> ws) {
        if (start) {
            start = 0;
        } else {
            cout << '\n';
        }

        string ligne;
        map<string, int> words;
        while (getline(cin, ligne), ligne != "EndOfText") {
            transform(ligne.begin(), ligne.end(), ligne.begin(), ::tolower);
            for (int i = 0; i < ligne.size(); ++i) {
                if (isalpha(ligne[i])) {
                    string word = "";
                    while (isalpha(ligne[i])) {
                        word += ligne[i];
                        i++;
                    }
                    words[word]++;
                }
            }
        }
        int found = 0;
        for (auto &word: words) {
            if (word.second == n) {
                cout << word.first << '\n';
                found = 1;
            }
        }
        if (!found) {
            cout << "There is no such word." << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

