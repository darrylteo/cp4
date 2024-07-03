#include <bits/stdc++.h>

using namespace std;

// got TLE but ok after pruning. fun question in the sense that u check one forward one backward recursion
// if myMap[i][j] == 1 then there is a road between i and j
int dest, visited[24], path[24], cnt, myMap[24][24];

void pruneVisited(int node) {
    if (!visited[node]) return; // don't do anything if already can visit here
    visited[node] = 0; // this node is reachable
    for (int i = 1; i <= 20; i++) {
        if (myMap[node][i]) {
            pruneVisited(i);
        }
    }
}

void dfs(int node, int depth) {
    if (node == dest) {
        cnt++;
        cout << "1";
        for (int i = 1; i < depth; i++) {
            cout << " " << path[i];
        }
        cout << "\n";
        return;
    }
    // max 20 streets
    for (int i = 1; i <= 20; i++) {
        if (myMap[node][i] && !visited[i]) {
            visited[i] = 1;
            path[depth] = i;
            dfs(i, depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, j, cases = 0;
    while (cin >> dest) {
        memset(myMap, 0, sizeof(myMap));
        memset(visited, 1, sizeof(visited));
        cnt = 0;
        while (cin >> i >> j, i) {
            myMap[i][j] = myMap[j][i] = 1;
        }
        cout << "CASE " << ++cases << ":\n";
        pruneVisited(dest);
        visited[1] = 1; // no matter what, don't come here again
        dfs(1, 1);
        cout << "There are " << cnt << " routes from the firestation to streetcorner " << dest << ".\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

