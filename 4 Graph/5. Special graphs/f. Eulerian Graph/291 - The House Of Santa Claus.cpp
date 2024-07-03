#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int adj[5][5] = {
        {0,1,1,0,1},
        {1,0,1,0,1},
        {1,1,0,1,1},
        {0,0,1,0,1},
        {1,1,1,1,0}
};
int ans[9];

void dfs(int idx, int curr) {
    ans[idx] = curr;
    if (idx == 8) {
        for (int i : ans) cout << i + 1;
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        if (adj[curr][i]) {
            adj[curr][i] = adj[i][curr] = 0;
            dfs(idx + 1, i);
            adj[curr][i] = adj[i][curr] = 1;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dfs(0,0);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

