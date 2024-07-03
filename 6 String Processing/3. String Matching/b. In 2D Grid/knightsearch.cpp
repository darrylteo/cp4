#include <bits/stdc++.h>

using namespace std;

int knightR[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knightC[] = {1, -1, 1, -1, 2, -2, 2, -2};
vector<string> grid;
int N;
string word = "ICPCASIASG";

inline int dfs(int pos, int r, int c) {
    if (pos == word.size()) return 1;
    if (r < 0 || r >= N || c < 0 || c >= N) return 0;
    if (grid[r][c] != word[pos]) return 0;
    for (int i = 0; i < 8; i++) {
        if (dfs(pos + 1, r + knightR[i], c + knightC[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;
    grid.resize(N);
    string buf;
    cin >> buf;
    for (int i = 0; i < N; i++) {
        grid[i] = buf.substr(i * N, N);
    }
    bool found = false;
    for (int i = 0; i < N && !found; i++) {
        for (int j = 0; j < N && !found; j++) {
            if (grid[i][j] == word[0]) {
                if (dfs(0, i, j)) {
                    found = true;
                }
            }
        }
    }
    cout << (found ? "YES" : "NO") << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


