#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};
struct stroke {
    int x1, y1, x2, y2;
};

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};
UnionFind *uf;
int R, C, Q;
vector<vector<int>> grid;
vector<stroke> strokes;
int blackCnt = 0;

void paint(int id) { // paint
    stroke s = strokes[id];
    for (int r = s.x1; r <= s.x2; ++r) {
        for (int c = s.y1; c <= s.y2; ++c) {
            grid[r][c]++;
        }
    }
}

void firstFloodFill() {
    vector<vector<int>> gridCopy = grid;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (gridCopy[r][c] == 0) {
                int idx = r * C + c;
                queue<pair<int, int>> q;
                q.emplace(r, c);
                gridCopy[r][c] = 1;
                while (!q.empty()) {
                    pair<int, int> u = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int nr = u.first + dirr[i], nc = u.second + dirc[i];
                        if (nr >= 0 && nr < R && nc >= 0 && nc < C && gridCopy[nr][nc] == 0) {
                            gridCopy[nr][nc] = 1;
                            q.emplace(nr, nc);
                            uf->unionSet(idx, nr * C + nc);
                        }
                    }
                }
            }
        }
    }
}

void unpaint(int id) { // unpaint
    stroke s = strokes[id];
    for (int r = s.x1; r <= s.x2; ++r) {
        for (int c = s.y1; c <= s.y2; ++c) {
            grid[r][c]--;
            if (grid[r][c] == 0) {
                blackCnt--;
                int idx = r * C + c;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dirr[i], nc = c + dirc[i];
                    if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0) {
                        uf->unionSet(idx, nr * C + nc);
                    }
                }
            }
        }
    }
}

void countBlack() {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            blackCnt += grid[r][c] > 0;
        }
    }
}

// we ufds the white squares as we "unpaint" the grid
// blackCnt squares are not ufds'd (so we can get the count of white groups = total grps - blackCnt grps)
// abit different from my usual coding style since i wanted to keep uf as a global variable (without initializing)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> Q;
    strokes.resize(Q);
    grid.resize(R, vector<int>(C));
    uf = new UnionFind(R * C);
    for (int i = 0; i < Q; ++i) {
        stroke &s = strokes[i];
        cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;
        --s.x1, --s.y1, --s.x2, --s.y2;
        paint(i);
    }
    firstFloodFill();
    vector<int> ans(Q);
    countBlack();
    for (int i = Q - 1; i >= 0; --i) {
        ans[i] = uf->numDisjointSets() - blackCnt;
        unpaint(i);
    }
    for (int i = 0; i < Q; ++i) cout << ans[i] << '\n';
    delete uf;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
