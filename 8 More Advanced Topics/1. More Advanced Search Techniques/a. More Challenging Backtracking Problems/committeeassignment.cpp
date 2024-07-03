#include <bits/stdc++.h>

using namespace std;

int n, m, grp, maxGrp;
vector<vector<int>> badAdj;
vector<int> groups;

// either put the person in existing group or create a new group
void dfs(int u) {
    if (grp >= maxGrp) return; // pruning (optimization)
    if (u == n) { // no. of grps using this configuration
        maxGrp = min(maxGrp, grp);
        return;
    }
    if (u == 0) { // always put the first person in group 0
        groups[u] = 0;
        dfs(u + 1);
        return;
    }

    // try to put the person in existing group
    for (int i = 0; i <= grp; i++) {
        bool ok = true;
        for (int v : badAdj[u]) {
            if (groups[v] == i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            groups[u] = i;
            dfs(u + 1);
        }
    }

    // create a new group
    groups[u] = ++grp;
    dfs(u + 1);
    grp--;
}

// first time finish hard qn in a few mins!!!!!

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n >> m, n) {
        if (!m) {
            cout << 1 << '\n';
            continue;
        }

        badAdj = vector<vector<int>>(n);
        groups = vector<int>(n, -1);
        grp = 0;
        maxGrp = 1e9;
        map<string, int> names;
        for (int i = 0; i < m; i++) {
            string name1, name2;
            cin >> name1 >> name2;
            if (names.find(name1) == names.end()) names[name1] = (int) names.size();
            if (names.find(name2) == names.end()) names[name2] = (int) names.size();
            badAdj[names[name1]].push_back(names[name2]);
            badAdj[names[name2]].push_back(names[name1]);
        }

        dfs(0);
        cout << maxGrp + 1 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}