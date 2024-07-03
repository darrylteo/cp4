#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int N = 51, adjMat[51][51], degree[51];
stack<ii> ans; // using vii is also ok but emplace (i, s) instead

inline void hierholzer(int s) {
    for (int i = 0; i < N; ++i) {
        if (adjMat[s][i]) {
            adjMat[s][i]--;
            adjMat[i][s]--;
            hierholzer(i);
            ans.emplace(s, i);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case #" << cases << '\n';
        int n;
        cin >> n;
        memset(adjMat, 0, sizeof adjMat);
        memset(degree, 0, sizeof degree);
        int start = 0;
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adjMat[u][v]++;
            adjMat[v][u]++;
            degree[u]++;
            degree[v]++;
            start = u; // actually, any vertex will do
        }
        int flag = 0;
        for (int i = 0; i < N; ++i) {
            if (degree[i] % 2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "some beads may be lost" << '\n';
            if (cases < T) cout << '\n';
            continue;
        }
        hierholzer(start);
        for (int i = 0; i < n; ++i) {
            ii e = ans.top();
            ans.pop();
            cout << e.first << " " << e.second << '\n';
        }
        if (cases < T) cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
