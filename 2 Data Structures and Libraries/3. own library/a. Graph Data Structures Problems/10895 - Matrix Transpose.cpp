#include <bits/stdc++.h>

using namespace std;

int m, n;

struct row {
    int pos, val;
};

void myPrint(const vector<vector<row>> &adj) {
    cout << n << " " << m << endl;
    for (int i = 0; i < adj.size(); ++i) {
        cout << adj[i].size();
        if (adj[i].empty()) {
            cout << endl;
            cout << endl;
            continue;
        }
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << " " << adj[i][j].pos;
        }
        cout << endl;
        cout << adj[i][0].val;
        for (int j = 1; j < adj[i].size(); ++j) {
            cout << " " << adj[i][j].val;
        }
        cout << endl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> m >> n) {
        vector<vector<row>> adj(n); // for final matrix (sparse)
        for (int i = 0; i < m; ++i) {
            int r;
            cin >> r;
            if (r == 0) continue;
            vector<int> rowNums(r);
            for (int j = 0; j < r; ++j) {
                cin >> rowNums[j];
            }
            vector<int> rowVals(r);
            for (int j = 0; j < r; ++j) {
                cin >> rowVals[j];
            }
            // 1 3 2 will be placed in (v[0]: pos = 1, val = 1),  (v[1]: pos = 1, val = 3), (v[2]: pos = 1, val = 2)
            for (int j = 0; j < r; ++j) {
                adj[rowNums[j] - 1].push_back({i + 1, rowVals[j]});
            }
        }
        myPrint(adj);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
