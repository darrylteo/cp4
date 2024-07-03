#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
unordered_map<string, int> visited;
unordered_map<string, vector<string>> adjList;
int done = 0;

void dfs(string node, string end) {
    if (done) return;
    if (node == end) {
        for (auto &i : ans) {
            cout << i << " ";
        }
        cout << endl;
        done = 1;
        return;
    }
    for (auto &i : adjList[node]) {
        if (!visited[i]) {
            visited[i] = 1;
            ans.push_back(i);
            dfs(i, end);
            ans.pop_back();
            visited[i] = 0;
        }
    }
}

// unsure how this is bicoloring/cyclecheck

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
        string first, s;
        ss >> first;
        while (ss >> s) {
            adjList[first].push_back(s);
            adjList[s].push_back(first);
        }
    }
    string start, end;
    cin >> start >> end;
    ans.push_back(start);
    visited[start] = 1;
    dfs(start, end);
    if (!done) cout << "no route found" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



