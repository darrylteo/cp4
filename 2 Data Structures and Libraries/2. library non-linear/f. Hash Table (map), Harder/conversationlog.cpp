#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    getline(cin, buf);
    int n = stoi(buf);
    set<string> names; // store unique names
    unordered_map<string, pair<unordered_set<string>, int>> words; // word and peepos who said it
    for (int i = 0; i < n; ++i) {
        getline(cin, buf);
        string s;
        stringstream ss(buf);
        ss >> s;
        string name = s;
        names.insert(name);
        while (ss >> s) {
            words[s].first.insert(name);
            words[s].second++;
        }
    }

    vector<pair<int, string>> v;
    int totalNames = names.size();
    for (auto &it: words) {
        if (it.second.first.size() == totalNames) {
            v.emplace_back(it.second.second, it.first);
        }
    }
    sort(v.begin(), v.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return a.first > b.first;
    });
    if (v.empty()) {
        cout << "ALL CLEAR" << endl;
    } else {
        for (auto &it: v) {
            cout << it.second << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
