#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int> iiii;
typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;

// UFDS code from ch2/ownlibrary/ufds.cpp
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }

    int numDisjointSets() { return numSets; }

    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

struct point {
    int x, y;

    point(int x, int y) : x(x), y(y) {}

    bool operator<(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

const int dirr[] = {0, 0, 1, -1};
const int dirc[] = {1, -1, 0, 0};

// using clue from book to multisource BFS. this gives us edges to add to the MST

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;
    map<point, int> pointMp; // point to id (to remove duplicates)
    vector<point> points;
    queue<point> q; // for BFS. point id.
    vector<vector<int>> vis(1000, vector<int>(1000, -1)); // record first guy that visted here.
    for (int i = 0; i < V; ++i) {
        int x, y;
        cin >> x >> y;
        point p(x, y);
        if (pointMp.find(p) == pointMp.end()) {
            pointMp[p] = points.size();
            points.push_back(p);
            vis[x][y] = pointMp[p];
            q.emplace(x, y);
        }
    }
    set<iii> EL; // w, u, v. sorted here
    while (!q.empty()) {
        int ux = q.front().x, uy = q.front().y;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int vx = ux + dirr[i], vy = uy + dirc[i];
            if (vx < 0 || vx >= 1000 || vy < 0 || vy >= 1000) continue;
            if (vis[vx][vy] != -1) { // already visited. add edge to MST
                int parent1 = vis[ux][uy], parent2 = vis[vx][vy];
                int w = abs(points[parent1].x - points[parent2].x) + abs(points[parent1].y - points[parent2].y);
                EL.emplace(w, parent1, parent2);
            } else {
                vis[vx][vy] = vis[ux][uy];
                q.emplace(vx, vy);
            }
        }
    }

    int mst_cost = 0, num_taken = 0;
    UnionFind UF(points.size());
    for (auto el : EL) {
        auto [w, u, v] = el;
        if (UF.isSameSet(u, v)) continue;
        mst_cost += w;
        UF.unionSet(u, v);
        ++num_taken;
        if (UF.numDisjointSets() == 1) break;
    }
    cout << mst_cost << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
