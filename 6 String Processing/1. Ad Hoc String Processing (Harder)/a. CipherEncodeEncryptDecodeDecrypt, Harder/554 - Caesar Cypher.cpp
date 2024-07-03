#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    set<string> dict;
    string s, letters = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (cin >> s) {
        if (s == "#") break;
        dict.insert(s);
    }
    string query;
    getline(cin >> ws, query);
    int numMatches = 0, bestKey = 0;
    for (int k = 1; k <= 26; ++k) {
        string s1 = query;
        for (char &c : s1) {
            int idx;
            if (c == ' ') idx = 0;
            else idx = c - 'A' + 1;
            idx = (idx + k) % 27;
            c = letters[idx];
        }
        int matches = 0;
        stringstream ss(s1);
        string word;
        while (ss >> word) {
            if (dict.count(word)) ++matches;
        }
        if (matches > numMatches) {
            numMatches = matches;
            bestKey = k;
        }
    }
    string s1 = query;
    for (char &c : s1) {
        int idx;
        if (c == ' ') idx = 0;
        else idx = c - 'A' + 1;
        idx = (idx + bestKey) % 27;
        c = letters[idx];
    }
    // print s1 but leave a line at most 60 characters long
    stringstream ss(s1);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    int len = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (len + words[i].size() + 1 <= 60) {
            if (len > 0) cout << " ";
            cout << words[i];
            len += words[i].size() + 1;
        } else {
            cout << "\n" << words[i];
            len = words[i].size();
        }
    }
    cout << "\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

