#include <bits/stdc++.h>

using namespace std;

// defined for convenience. was gonna name it ret for return value but rat reduce confusion.
struct rat {
    int lp, r2; // lampost, road with 2 lamposts

    bool operator<(const rat &rhs) const { // less lp and more 2 lp roads good
        if (lp != rhs.lp) return lp < rhs.lp;
        return r2 > rhs.r2;
    }

    rat operator+(const rat &rhs) const { // add two rats
        return {lp + rhs.lp, r2 + rhs.r2};
    }

    rat &operator+=(const rat &rhs) { // add two rats
        lp += rhs.lp;
        r2 += rhs.r2;
        return *this;
    }
};

typedef vector<int> vi;

rat memo[1010][2];
vector<vi> AL;                                   // undirected version
vector<vi> Children;                             // directed version
vi vis;

void dfs(int u) {
    vis[u] = true;
    for (auto &v: AL[u])
        if (!vis[v]) {
            Children[u].push_back(v);                  // now u<->v becomes u->v
            dfs(v);
        }
}

rat MVC(int u, int flag) {
    rat &ans = memo[u][flag];
    if (ans.lp != -1) return ans;
    if ((int) Children[u].size() == 0) ans = {flag, 0};  // u is a leaf just record taken or not
    else if (flag == 0) { // if u is not taken, take all children
        ans = {0, 0};
        for (auto &v: Children[u])
            ans += MVC(v, 1);
    } else if (flag == 1) { // if u is taken, choose best between take or not
        ans = {1, 0};
        rat r22 = {0, 1};
        for (auto &v: Children[u]) ans += min(MVC(v, 1) + r22, MVC(v, 0));
    }
    return ans;
}

// probably any node with only 1 edge may be a root
// almost same as uva 10243 given in book except var r22 key modification.
// when curr node picked, and we pick his children, count 1 double lampost road

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        AL.assign(V, vi());
        Children.assign(V, vi());
        vis.assign(V, 0);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }
        vi treeRoots;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                treeRoots.push_back(i);
                dfs(i);
            }
        }
        rat ans = {0, 0};
        for (auto &root: treeRoots) ans += min(MVC(root, 0), MVC(root, 1));
        cout << ans.lp << ' ' << ans.r2 << ' ' << E - ans.r2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}