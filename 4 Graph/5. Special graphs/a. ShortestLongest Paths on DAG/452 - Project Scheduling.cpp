#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

// similar to fibtour kattis

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    string buf;
    getline(cin, buf);
    T = stoi(buf);
    getline(cin, buf);
    while (T--) {
        vector<vii> adj(26);
        vi inDegree(26, 0), startNodeWeight(26, 0);
        while (getline(cin, buf) && !buf.empty()) {
            stringstream ss(buf);
            char u;
            int w;
            string v;
            ss >> u >> w >> v;
            for (char c: v) {
                adj[c - 'A'].emplace_back(u - 'A', w);
                inDegree[u - 'A']++;
            }
            if (v.empty()) {
                startNodeWeight[u - 'A'] = w;
            }
        }

        // process all nodes with inDegree == 0 and find longest path
        queue<int> q;
        vi dist(26, 0);
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                dist[i] = startNodeWeight[i];
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, w]: adj[u]) {
                inDegree[v]--;
                dist[v] = max(dist[v], dist[u] + w);
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        cout << *max_element(dist.begin(), dist.end()) << "\n";
        if (T) cout << "\n";
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}