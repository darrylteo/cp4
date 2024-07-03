#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// get more money if for a:b if a/b < 1 and less money if a/b > 1
// can use -log(a/b)
// let's check using SGD:USD = 1.4 and SGD:EUR = 1.5
// check if USD:EUR = 1.5/1.4 = 1.0714
// log(1/1.4) + log(1.5) = (log(1.5/1.4)) // can be combined without loss of generality



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n, n) {
        map<string, int> mp;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mp[s] = i;
        }
        double grid[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1e9;
            }
            grid[i][i] = 0;
        }
        cin >> m;
        while (m--) {
            int u, v;
            double w;
            cin >> s;
            u = mp[s];
            cin >> s;
            v = mp[s];
            cin >> s;
            istringstream ss(s);
            getline(ss, s, ':');
            int a = stoi(s);
            getline(ss, s, ':');
            int b = stoi(s);
            w = log((double) a / b);
            grid[u][v] = min(grid[u][v], w);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (grid[i][i] < 0) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Arbitrage" : "Ok") << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




