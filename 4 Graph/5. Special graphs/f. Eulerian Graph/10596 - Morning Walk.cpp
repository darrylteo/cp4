#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// note that while textbook states:
//          If all the vertices except exactly two vertices have an even degree,
//          then the graph has an Eulerian path which starts at one of the two odd-degree vertices and ends at the other.
// for this question he want to walk back home so ALL must be even

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    next:
    while (cin >> n >> m) {
        int graph[n][n];
        memset(graph, 0, sizeof(graph));
        vi degree(n, 0), exist(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
                degree[u]++;
                degree[v]++;

            graph[u][v] = graph[v][u] = 1;
            exist[u] = exist[v] = 1;
        }

        // check if graph is connected. we do bfs but floyd is ok too since small (200 vertices)
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (exist[i]) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            cout << "Not Possible\n";
            goto next;
        }
        vi visited(n, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (graph[u][v] && !visited[v]) {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (exist[i] && !visited[i]) {
                cout << "Not Possible\n";
                goto next;
            }
        }

        // check if all vertices have even degree
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (degree[i] % 2) {
                cnt++;
            }
        }
        if (cnt == 0) {
            cout << "Possible\n";
        } else {
            cout << "Not Possible\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
