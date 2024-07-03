#include <bits/stdc++.h>

using namespace std;

vector<string> dict, queries;
bool done = false;
vector<char> q2d; // query to dict map. {x, y, z, ...} means a -> x, b -> y, c -> z. '-' means free.

void dfs(int idx) {
    if (done) return;
    if (idx == queries.size()) {
        done = true;
        for (int i = 0; i < queries.size(); i++) {
            if (i) cout << " ";
            for (char c : queries[i]) cout << q2d[c - 'a'];
        }
        cout << '\n';
        return;
    }

    string query = queries[idx];
    for (string &dic: dict) {
        if (dic.size() != query.size()) continue;
        bool valid = true;
        vector<char> q2d_bak = q2d; // backup
        for (int i = 0; i < dic.size(); i++) {
            if (q2d[query[i] - 'a'] == '-' || q2d[query[i] - 'a'] == dic[i]) {
                q2d[query[i] - 'a'] = dic[i];
            } else {
                valid = false;
                break;
            }
        }
        vector<int> cnt(26, 0);
        for (char c: q2d) if (c != '-') { // make sure no 2 letters map to same letter
            if (++cnt[c - 'a'] > 1) {
                valid = false;
                break;
            }
        }
        if (valid) dfs(idx + 1);
        q2d = q2d_bak; // restore
    }
}

// for each word in query, check if can replace by a word in dict.
// dfs into next word in query. if reach end then win and print sol.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        dict.push_back(s);
    }
    cin >> ws;
    string buf;
    while (getline(cin, buf)) {
        queries.clear();
        done = false;
        q2d.assign(26, '-');
        stringstream ss(buf);
        string s;
        while (ss >> s) queries.push_back(s);
        dfs(0);
        if (!done) {
            for (char c: buf) {
                if (c == ' ') cout << " ";
                else cout << '*';
            }
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
