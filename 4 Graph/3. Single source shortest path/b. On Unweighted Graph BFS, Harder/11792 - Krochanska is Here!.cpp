#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, l;
        cin >> n >> l;
        int important[n];
        memset(important, -1, sizeof(important)); // more than 1 is important
        vector<int> adj[n];
        cin >> ws;
        for (int i = 0; i < l; i++) {
            int prev, curr;
            cin >> prev;
            important[prev - 1]++;
            while (cin >> curr, curr) {
                important[curr- 1]++;
                adj[prev - 1].push_back(curr - 1);
                adj[curr - 1].push_back(prev - 1);
                prev = curr;
            }
        }

        vector<int> times(n, 0); // times to reach all other important nodes (only for important nodes != -1)
        for (int i = 0; i < n; i++) {
            if (important[i] > 0) {
                vector<int> dist(n, -1);
                queue<int> q;
                q.push(i);
                dist[i] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int j = 0; j < adj[u].size(); j++) {
                        int v = adj[u][j];
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }

                // check time to all other important stations
                for (int j = 0; j < n; j++) {
                    if (important[j] > 0) {
                        times[i] += dist[j];
                    }
                }

            }
        }

        int min_time = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (important[i] > 0) {
                min_time = min(min_time, times[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (important[i] > 0 && times[i] == min_time) {
                cout << "Krochanska is in: " << i + 1 << endl;
                break;
            }
        }


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}