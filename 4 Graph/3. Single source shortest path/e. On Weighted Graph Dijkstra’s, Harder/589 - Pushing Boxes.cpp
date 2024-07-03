#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const char dir[] = {'N', 'E', 'W', 'S'};

int used[25][25][25][25];
int step[25][25][25][25];
char grid[25][25];

// person (x, y) and box (a, b) and cost to come here
struct Node {
    int x, y, a, b, v;
};

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.v > b.v;
    }
};

void print(int x, int y, int a, int b) {
    // note these are opposite of the direction
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};

    if (used[x][y][a][b] == 1) return;
    for (int i = 0; i < 4; ++i) {
        if (step[x][y][a][b] == dir[i]) { // caps so both box and person moves
            print(x + dr[i], y + dc[i], a + dr[i], b + dc[i]);
        }
        if (step[x][y][a][b] == dir[i] + 32) { // small so only person moves
            print(x + dr[i], y + dc[i], a, b);
        }
    }
    cout << (char) step[x][y][a][b];
}

// hard qn. dijkstra within dijkstra
// ref: https://github.com/morris821028/UVa/blob/master/volume005/589%20-%20Pushing%20Boxes.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int R, C, cases = 1;
    while (cin >> R >> C, R) {
        // actual direction
        int dr[4] = {-1,0,0,1};
        int dc[4] = {0,1,-1,0}; // NEWS/news

        cout << "Maze #" << cases++ << endl;
        for (int i = 0; i < R; ++i) cin >> grid[i];
        memset(used, 0, sizeof used);
        int bx, by, px, py, ex, ey; // box, person, end
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 'B') bx = i, by = j;
                if (grid[i][j] == 'S') px = i, py = j;
                if (grid[i][j] == 'T') ex = i, ey = j;
            }
        }
        used[px][py][bx][by] = 1;
        priority_queue<Node, vector<Node>, cmp> pq;
        pq.push({px, py, bx, by, 1});
        Node tn{};
        int tx, ty, ta, tb;
        int sol = 0;
        while (!pq.empty()) {
            tn = pq.top();
            pq.pop();
            if (tn.a == ex && tn.b == ey) { // found ans
                print(tn.x, tn.y, tn.a, tn.b);
                cout << endl;
                sol = 1;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                if (tn.a == tn.x + dr[i] && tn.b == tn.y + dc[i]) { // person step on box (push box in direction)
                    tx = tn.x + dr[i];
                    ty = tn.y + dc[i];
                    ta = tn.a + dr[i];
                    tb = tn.b + dc[i];
                    if (ta < 0 || ta >= R || tb < 0 || tb >= C || grid[ta][tb] == '#') continue;
                    int *p = &used[tx][ty][ta][tb];
                    if (*p <= used[tn.x][tn.y][tn.a][tn.b] + 100000 && *p) continue; // came before and not improving
                    *p = used[tn.x][tn.y][tn.a][tn.b] + 100000; // new cost
                    step[tx][ty][ta][tb] = dir[i]; // N, E, W, S
                    pq.push({tx, ty, ta, tb, *p});
                }
            }
            for (int i = 0; i < 4; ++i) {
                if (tn.x + dr[i] == tn.a && tn.y + dc[i] == tn.b) continue; // person step on box (should use above code)
                tx = tn.x + dr[i];
                ty = tn.y + dc[i];
                ta = tn.a;
                tb = tn.b;
                if (tx < 0 || tx >= R || ty < 0 || ty >= C || grid[tx][ty] == '#') continue;
                int *p = &used[tx][ty][ta][tb];
                if (*p <= used[tn.x][tn.y][tn.a][tn.b] + 1 && *p) continue; // came before and not improving
                *p = used[tn.x][tn.y][tn.a][tn.b] + 1; // new cost
                step[tx][ty][ta][tb] = dir[i] + 32; // n, e, w, s
                pq.push({tx, ty, ta, tb, *p});
            }
        }
        if (!sol) cout << "Impossible." << endl;
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
