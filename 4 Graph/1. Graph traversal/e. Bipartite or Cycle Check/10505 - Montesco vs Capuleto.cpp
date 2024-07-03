#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;
    while (M--) {
        unordered_set<int> adj[205]; // 1 indexed
        int N;
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            int n;
            cin >> n;
            while (n--) {
                int x;
                cin >> x;
                if (x > N) continue; // weird but it is a hint on uDebug
                adj[i].insert(x);
                adj[x].insert(i);
            }
        }

        vector<int> color(N + 1, -1);
        int ans = 0;

        for (int i = 1; i <= N; ++i) {
            // important to decide for each set of frenemies, which color to choose for first friend in set
            // i.e. always setting first friend in set to 0 will get WA
            int color0 = 0, color1 = 0;
            bool isBipartite = true;
            if (color[i] == -1) {
                color[i] = 0;
                color0++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) { // don't break here, need to check all frenemies for this set even if not bipartite!
                    int u = q.front();
                    q.pop();
                    for (auto v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                            if (color[v] == 0) {
                                color0++;
                            } else {
                                color1++;
                            }
                        } else if (color[v] == color[u]) {
                            isBipartite = false;
                        }
                    }
                }
            }
            if(isBipartite) ans += max(color0, color1);
        }

        cout << ans << "\n";
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
