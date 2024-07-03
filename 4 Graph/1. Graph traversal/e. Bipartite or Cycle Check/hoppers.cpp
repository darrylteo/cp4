#include <bits/stdc++.h>

using namespace std;

// bipartite is used here means all the left guys can go to right guy and back to left. so left can infect left, right can infect right. connect 1 left to 1 left and can infect all
// say we have 3 CC, all bipartite, then we need 2 links to connect all 3 and 1 more to connect a CC to be non bipartite
// if 1 CC is non bipartite, then we need 2 link to connect all 3 CC and no need to make a non bipartite CC anymore

vector<int> adj[500005];
int visited[500005], color[500005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(color, -1, sizeof(color));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int bipartite = 0, CC = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            CC++;
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
                    } else if (color[v] == color[u]) {
                        bipartite = 1;
                    }
                }
            }
        }
    }


    if (bipartite) {
        cout << CC - 1 << endl;
    } else {
        cout << CC << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



