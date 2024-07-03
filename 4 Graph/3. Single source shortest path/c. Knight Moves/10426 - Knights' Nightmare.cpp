#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

// ref: https://mypaper.pchome.com.tw/zerojudge/post/1326963368
// had same idea but implementation problem WA many times. pass on udebug, fail on uva.

// [x][y][knights][dragon exists]
int ret[4][20][20], ret2[4][20][20];

void bfs(int dist[20][20], int sx, int sy, int n, int m, int mx, int my) {
    queue<int> X, Y;
    int tx, ty, i;
    dist[sx][sy] = 1;
    X.push(sx), Y.push(sy);
    while (!X.empty()) {
        sx = X.front(), X.pop();
        sy = Y.front(), Y.pop();
        for (i = 0; i < 8; i++) {
            tx = sx + dx[i], ty = sy + dy[i];
            if (tx <= 0 || ty <= 0 || tx > n || ty > m)
                continue;
            if (tx == mx && ty == my) continue;
            if (dist[tx][ty] == 0) {
                dist[tx][ty] = dist[sx][sy] + 1;
                X.push(tx), Y.push(ty);
            }
        }
    }
}

void bfs2(int dist[20][20], int sx, int sy, int n, int m) {
    queue<int> X, Y;
    int tx, ty, i;
    dist[sx][sy] = 1;
    X.push(sx), Y.push(sy);
    while (!X.empty()) {
        sx = X.front(), X.pop();
        sy = Y.front(), Y.pop();
        for (i = 0; i < 8; i++) {
            tx = sx + dx[i], ty = sy + dy[i];
            if (tx <= 0 || ty <= 0 || tx > n || ty > m) continue;
            if (dist[tx][ty] == 0) {
                dist[tx][ty] = dist[sx][sy] + 1;
                X.push(tx), Y.push(ty);
            }
        }
    }
}

int test(int x, int y ) {
    int time = 0;
    int i;
    for(i = 0; i < 4; i++) {
        if(ret[i][x][y] == 0) // can't search
            return 0xfffffff;
        time += ret[i][x][y];
    }
    int mntime = 0xfffffff;
    for(i = 0; i < 4; i++) {
        if(ret2[i][x][y] == 0)
            continue;
        mntime = min(mntime, time - ret[i][x][y] + ret2[i][x][y] - 4); // base 4
    }
    return mntime;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (cin >> s) {
        cout << s << '\n';
        int n, m, sx[4], sy[4], mx, my;
        cin >> n >> m;
        for (int i = 0; i < 4; i++)
            cin >> sx[i] >> sy[i];
        cin >> mx >> my;
        memset(ret, 0, sizeof(ret));
        memset(ret2, 0, sizeof(ret2));
        for (int i = 0; i < 4; i++) {
            bfs(ret[i], sx[i], sy[i], n, m, mx, my);
            bfs2(ret2[i], sx[i], sy[i], n, m);
        }
        int mntime = 0xfffffff;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == mx && j == my)
                    continue;
                mntime = min(mntime, test(i, j));
            }
        }
        if (mntime != 0xfffffff)
            cout << "Minimum time required is " << mntime << " minutes.\n";
        else
            cout << "Meeting is impossible.\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

