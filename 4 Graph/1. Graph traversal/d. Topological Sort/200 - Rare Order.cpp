#include <bits/stdc++.h>

using namespace std;

vector<int> adjList[30];
int used[30], visited[30]; // used if letter appears. visited is for dfs
vector<int> ans;

void dfs(int u) {
    visited[u] = 1;
    for (auto v : adjList[u]) {
        if (!visited[v]) dfs(v);
    }
    ans.push_back(u);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string prev, curr;
    while(cin >> prev) {
        memset(used, 0, sizeof used);
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < 30; ++i) adjList[i].clear();
        ans.clear();
        while (cin >> curr) {
            if (curr == "#") break;
            int len = min(prev.length(), curr.length());
            for (int i = 0; i < len; ++i) {
                if (prev[i] != curr[i]) {
                    adjList[prev[i] - 'A'].push_back(curr[i] - 'A'); // prev points to curr
                    used[prev[i] - 'A'] = used[curr[i] - 'A'] = 1;
                    break;
                }
            }
            prev = curr;
        }

        // special case when only 1 line
        int allZero = 1;
        for (int i = 0; i < 26; ++i) {
            if (used[i]) {
                allZero = 0;
                break;
            }
        }
        if (allZero) {
            cout << prev[0] << endl;
            continue;
        }


        for (int i = 0; i < 26; ++i) {
            if (used[i] && !visited[i]) dfs(i);
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans) cout << char(x + 'A');
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



