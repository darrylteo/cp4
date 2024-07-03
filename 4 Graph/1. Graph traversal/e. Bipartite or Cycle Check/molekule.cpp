#include <bits/stdc++.h>

using namespace std;

// if all point from left to right, max length is 1
// N-1 edges so must be bipartitable (no cycle if it is connected)

vector<int> adj[100005];
int visited[100005], color[100005], first[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(color, -1, sizeof(color));
    int N;
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        first[i] = u;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // standard bicoloring code
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            stack<int> st;
            st.push(i);
            visited[i] = 1;
            color[i] = 0;
            while (!st.empty()) {
                int u = st.top();
                st.pop();
                for (auto v: adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        color[v] = 1 - color[u];
                        st.push(v);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N - 1; ++i) {
        if (color[first[i]] == 0) cout << 0 << '\n';
        else cout << 1 << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



