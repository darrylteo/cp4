#include <bits/stdc++.h>

using namespace std;

// this time only point to 1 person (tested on uDebug that 1 martin does not send to multiple martins)
// probably the wrong way since it is slow but just pass
int neig[50005], visited[50005], visited2[50005], CCSize;

void dfs(int node) {
    visited[node] = visited2[node] = 1;
    CCSize++;
    if (!visited[neig[node]]) {
        dfs(neig[node]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            int u, v;
            cin >> u >> v;
            neig[u] = v;
        }

        memset(visited2, 0, sizeof(visited2));
        int idxBestStart = 0, bestCCSize = 0;
        for (int i = 1; i <= n; ++i) {
            if (visited2[i]) continue; // so that we don't visit the same (smaller) cycles again
            memset(visited, 0, sizeof(visited));
            CCSize = 0;
            dfs(i);
            if (CCSize == n) {
                idxBestStart = i;
                break;
            }
            if (CCSize > bestCCSize) {
                bestCCSize = CCSize;
                idxBestStart = i;
            }
        }

        cout << "Case " << cases << ": " << idxBestStart << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
