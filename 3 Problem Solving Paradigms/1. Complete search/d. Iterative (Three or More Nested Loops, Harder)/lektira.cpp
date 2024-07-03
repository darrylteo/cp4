#include <bits/stdc++.h>

using namespace std;

// simulate entire process since max length 50

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> words;
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            string word1 = s.substr(0, i);
            string word2 = s.substr(i, j - i);
            string word3 = s.substr(j, s.size() - j);
            reverse(word1.begin(), word1.end());
            reverse(word2.begin(), word2.end());
            reverse(word3.begin(), word3.end());
            words.insert(word1 + word2 + word3);
        }
    }
    cout << *words.begin() << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
