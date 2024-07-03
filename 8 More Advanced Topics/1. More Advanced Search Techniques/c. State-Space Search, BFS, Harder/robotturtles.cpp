#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// NESW
vector<int> dirr = {-1, 0, 1, 0};
vector<int> dirc = {0, 1, 0, -1};

struct hashh {
    size_t operator()(const tuple<int, int, int, ull> &t) const {
        return hash<int>()(get<0>(t)) ^ hash<int>()(get<1>(t)) ^ hash<int>()(get<2>(t)) ^ hash<ull>()(get<3>(t));
    }
};

// slow solution. a quick google search shows that dijkstra is preferred, since the graph is kinda weighted, with melt ice castle count as 2 moves

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<string> grid(8);
    for (int i = 0; i < 8; i++) cin >> grid[i];
    int x = 7, y = 0, dir = 1; // bottom left facing right
    int tx, ty;
    ull board = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == 'D') {
                tx = i;
                ty = j;
            }
            if (grid[i][j] == 'I') board |= (1ULL << (i * 8 + j)); // marked ice castles
        }
    }
    unordered_map<tuple<int, int, int, ull>, string, hashh> dist;
    queue<tuple<int, int, int, ull>> q;
    q.emplace(x, y, dir, board);
    dist[{x, y, dir, board}] = "";
    while (!q.empty()) {
        auto [x, y, dir, board] = q.front();
        q.pop();
        if (x == tx && y == ty) {
            cout << dist[{x, y, dir, board}] << endl;
            return 0;
        }
        // blast ice or move forward
        int nx = x + dirr[dir];
        int ny = y + dirc[dir];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 &&
            grid[nx][ny] != 'C') { // in front of him is within bounds and not rock
            if (board & (1ULL << (nx * 8 + ny))) { // blast ice castle
                ull newBoard = board ^ (1ULL << (nx * 8 + ny)); // remove ice castle
                if (dist[{x,y,dir,newBoard}].empty()) {
                    dist[{x,y,dir,newBoard}] = dist[{x,y,dir,board}] + "X"; // blast
                    q.emplace(x, y, dir, newBoard);
                }
            } else {
                dist[{nx, ny, dir, board}] = dist[{x, y, dir, board}] + "F"; // move forward
                q.emplace(nx, ny, dir, board);
            }
        }
        // turn left
        int ndir = (dir + 3) % 4;
        if (dist[{x, y, ndir, board}].empty()) {
            dist[{x, y, ndir, board}] = dist[{x, y, dir, board}] + "L"; // left
            q.emplace(x, y, ndir, board);
        }
        // turn right
        ndir = (dir + 1) % 4;
        if (dist[{x, y, ndir, board}].empty()) {
            dist[{x, y, ndir, board}] = dist[{x, y, dir, board}] + "R"; // right
            q.emplace(x, y, ndir, board);
        }
    }
    cout << "no solution" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}