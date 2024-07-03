#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> dependencies;
unordered_map<string, bool> visited;
vector<string> ans;

void dfs(const string& key) {
    if (visited[key]) return;
    visited[key] = true;
    for (const string& value : dependencies[key]) {
        dfs(value);
    }
    ans.push_back(key);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string buf;
    getline(cin, buf);
    n = stoi(buf);
    while (n--) {
        getline(cin, buf);
        stringstream ss(buf);
        string key, value;
        getline(ss, key, ':');
        while (getline(ss, value, ' ')) {
            if (value.empty()) continue;
            dependencies[value].push_back(key);
        }
    }
    getline(cin, buf);
    dfs(buf);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



