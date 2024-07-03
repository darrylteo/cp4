#include <bits/stdc++.h>

using namespace std;

// e.g.             0
//                /   \
//               1     2
//                \   /
//                  3

// weights look like this
//                  1
//                /   \
//               0     0
//                \   /
//                  0

// after 1 iter
//                  0
//                /   \
//               1/2   1/2
//                \   /
//                  0

// after 2 iter
//                  1/4+1/4
//                /   \
//               0      0
//                \   /
//                  1/4+1/4 (gets absorbed and add to ans 1/4+1/4 * 2)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    vector<int> adj[20];
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<double> prevE(20,0);
    double ans = 0;
    int time = 0;
    prevE[0] = 1;
    while (time++ < 10000) {
        vector<double> E(20, 0); // E is a temp array that gets the "shared values"
        for (int i = 0; i < N; i++) {
            if (prevE[i] == 0) continue;
            for (int j = 0; j < adj[i].size(); j++) {
                E[adj[i][j]] += prevE[i] / adj[i].size(); // shares its values to its neighbours
            }
        }
        ans += E[N - 1] * time;
        E[N - 1] = 0; // reset the value of the last node
        prevE = E;
    }
    cout << fixed << setprecision(10) << ans << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
