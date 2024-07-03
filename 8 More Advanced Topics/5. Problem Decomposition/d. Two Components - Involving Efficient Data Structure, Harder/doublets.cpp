#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> w2i; // word to idx.
unordered_map<int, string> i2w; // idx to word
vector<int> adj[25150];
unordered_set<string> words;

void adjList(const string& word) {
    for (int i = 0; i < word.size(); ++i) {
        string temp = word;
        for (char c = 'a'; c <= 'z'; ++c) {
            temp[i] = c;
            if (words.find(temp) != words.end()) {
                adj[w2i[temp]].push_back(w2i[word]);
                adj[w2i[word]].push_back(w2i[temp]);
            }
        }
    }
}

vector<int> parent(25150, -1);
void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(25150, false);
    parent[start] = -1;
    parent[end] = -1;
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end) return;
        for (int i = 0; i < adj[cur].size(); ++i) {
            int next = adj[cur][i];
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

// graph from each word to its doublets. then bfs from start to end.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    int idx = 0;
    while (getline(cin, buf)) {
        if (buf.empty()) break;
        words.insert(buf);
        w2i[buf] = idx;
        i2w[idx] = buf;
        adjList(buf);
        ++idx;
    }

    string start, end;
    int st = 1;
    while (cin >> start >> end) {
        if (st) st = 0;
        else cout << '\n';
        if (start.size() != end.size()) {
            cout << "No solution.\n";
            continue;
        }
        int startIdx = w2i[start];
        int endIdx = w2i[end];
        bfs(startIdx, endIdx);
        if (parent[endIdx] == -1) {
            cout << "No solution.\n";
        } else {
            vector<int> path;
            for (int i = endIdx; i != -1; i = parent[i]) {
                path.push_back(i);
            }
            for (int i = path.size() - 1; i >= 0; --i) {
                cout << i2w[path[i]] << '\n';
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}

