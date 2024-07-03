#include <bits/stdc++.h>

using namespace std;

vector<int> dist;

const int dirr[] = {-1, 1, 0, 0};
const int dirc[] = {0, 0, -1, 1};



int memo[3005][105];
int R, C, B, S;
vector<string> grid;

void flood(int sx, int sy, char color) {
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '#') continue;
        grid[x][y] = color;
        for (int i = 0; i < 4; i++) {
            q.emplace(x + dirr[i], y + dirc[i]);
        }
    }
}

int dfs(int prev, int rem) { // location of previous bridge. remember to have S separation
    if (rem == 0) return 0; // 良い結果
    int &ans = memo[prev][rem];
    if (ans != -1) return ans;
    ans = 1e9;
    for (int i = 0; i < C; i++) {
        if (prev - i - 1 < S) continue; // 近くに橋がある
        ans = min(ans, dist[i] + dfs(i, rem-1)); // ここに橋を建設します
        ans = min(ans, dfs(prev, rem)); // ここに橋を建設しません
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> R >> C >> B >> S) {
        grid.resize(R);
        for (int i = 0; i < R; i++) cin >> grid[i];
        // first, flood north (bank) with 1, south with 2
        flood(0,0, '1');
        flood(R-1, C-1, '2');
        // for each col, get dist to other side
        dist.assign(C, 0);
        for (int j = 0; j < C; j++) {
            int top = -1, bot = -1;
            for (int i = 0; i < R; i++) if (grid[i][j] == '1') top = i;
            for (int i = R-1; i >= 0; i--) if (grid[i][j] == '2') bot = i;
            dist[j] = bot - top - 1;
        }
        memset(memo, -1, sizeof(memo));
        cout << dfs(3000, B) << endl; // build from right so that first bridge not constrained
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
