#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but shortcuts are useful in competitive programming

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int V, cases = 1;
    while (cin >> V, V) {
        map<string, int> mapper;
        vector<vi> AL(35, vi());
        int idx = 1; // 1 indexed
        string s1, s2;
        for (int i = 0; i < V; i++) {
            cin >> s1 >> s2;
            if (mapper[s1] == 0) {
                mapper[s1] = idx++;
            }
            if (mapper[s2] == 0) {
                mapper[s2] = idx++;
            }
            AL[mapper[s1]].emplace_back(mapper[s2]);
            AL[mapper[s2]].emplace_back(mapper[s1]); // back to 0 indexed
        }

        string s;
        int TTL;
        while (cin >> s >> TTL) {
            if (s == "0" && TTL == 0) break;
            vi dist(mapper.size() + 1, 1e9); // 1 indexed
            if (mapper[s] == 0) {
                cout << "Case " << cases++ << ": " << mapper.size() - 1 << " nodes not reachable from node " << s << " with TTL = " << TTL << ".\n";
                mapper.erase(s); // since we shortcut using find
                continue;
            }

            dist[mapper[s]] = 0;
            queue<int> q;
            q.push(mapper[s]);

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: AL[u]) {
                    if (dist[v] == 1e9) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            int unreachable = 0;
            for (int i : dist) {
                if (i > TTL) unreachable++;
            }
            cout << "Case " << cases++ << ": " << unreachable - 1 << " nodes not reachable from node " << s << " with TTL = " << TTL << ".\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}