#include <bits/stdc++.h>

using namespace std;

// since max int value here is 10^6, memory is bad but still ok
// alternatively map<int, vector<int>> i think shd be ok

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m){
        vector<vector<int>> adj(1000000); // stores the k-th occurrence of each node
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x; --x;
            adj[x].push_back(i);
        }
        for (int i = 0; i < m; ++i) {
            int k, v;
            cin >> k >> v; --k; --v;
            if (adj[v].size() <= k) {
                cout << 0 << '\n';
            } else {
                cout << adj[v][k] + 1 << '\n';
            }
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
