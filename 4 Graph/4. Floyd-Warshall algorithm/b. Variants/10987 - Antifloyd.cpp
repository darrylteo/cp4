#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// grid2 marks edges to delete. grid2[i][j] = 1 means delete edge i-j
int grid[100][100], n;

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 1e9;
        }
        grid[i][i] = 0;
    }
}

void getInput() {
    int w;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            cin >> w;
            grid[i][j] = grid[j][i] = w;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case #" << cases << ":\n";
        cin >> n;
        reset();
        getInput();
        // if the given graph is not shortest path, it signifies an error
        int flag = 0;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] > grid[i][k] + grid[k][j]) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag) {
            cout << "Need better measurements.\n\n"; // double new line
            continue;
        }
        vector<iii> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int iToj = 1;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j && grid[i][j] == grid[i][k] + grid[k][j]) {
                        iToj = 0; // found alternative way to go from i to j
                        break;
                    }
                }
                if (iToj) { // no alternative so MUST use this edge
                    ans.emplace_back(min(i, j) + 1, max(i, j) + 1, grid[i][j]);
                }
            }
        }
        if (ans.empty()) {
            cout << "Need better measurements.\n\n"; // double new line
            continue;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto &x: ans) {
            cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
        }
        cout << "\n"; // double new line
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




