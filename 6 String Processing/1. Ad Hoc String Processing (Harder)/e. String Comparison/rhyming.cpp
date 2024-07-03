#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n >> ws;
    set<string> rhymes;
    while (n--) {
        string buf;
        vector<string> tmp;
        getline(cin, buf);
        stringstream ss(buf);
        string word;
        int rhymeSet = 0;
        while (ss >> word) {
            if (s.substr(max(0, (int) (s.size()-word.size()))) == word) {
                rhymeSet = 1;
            }
            tmp.push_back(word);
        }
        if (rhymeSet) {
            for (auto &t : tmp) {
                rhymes.insert(t);
            }
        }
    }

    int q;
    cin >> q >> ws;
    while (q--) {
        string buf;
        getline(cin, buf);
        int found = 0;
        for (const string& word : rhymes) {
            if (buf.substr(max(0, (int) (buf.size()-word.size()))) == word) {
                cout << "YES\n";
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "NO\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

