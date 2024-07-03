#include <bits/stdc++.h>

using namespace std;

int labss[100005], inDegree1[100005], inDegree2[100005];
vector<int> adjList[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        memset(inDegree1, 0, sizeof(inDegree1)); // for lab 1 start
        memset(inDegree2, 0, sizeof(inDegree2)); // for lab 2 start
        for (int i = 1; i <= n; ++i) {
            adjList[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            cin >> labss[i];
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            inDegree1[b]++;
            inDegree2[b]++;
        }

        // for lab 1 start
        int ans1 = 0, currLab = 1;
        vector<queue<int>> q(3);
        // find which items can be processed (no dependencies)... nodes that are not connected also go here
        for (int i = 1; i <= n; ++i) {
            if (inDegree1[i] == 0) {
                if (labss[i] == 1) q[1].push(i);
                else q[2].push(i);
            }
        }
        while (!q[1].empty() || !q[2].empty()) {
            while (!q[currLab].empty()) {
                int u = q[currLab].front();
                q[currLab].pop();
                for (int v : adjList[u]) {
                    inDegree1[v]--;
                    if (inDegree1[v] == 0) {
                        if (labss[v] == 1) q[1].push(v);
                        else q[2].push(v);
                    }
                }
            }

            // go to next lab
            if (currLab == 1) currLab = 2;
            else currLab = 1;
            ans1++;
        }

        // for lab 2 start (copy paste)
        int ans2 = 0;
        currLab = 2;
        // find which items can be processed (no dependencies)
        for (int i = 1; i <= n; ++i) {
            if (inDegree2[i] == 0) {
                if (labss[i] == 1) q[1].push(i);
                else q[2].push(i);
            }
        }
        while (!q[1].empty() || !q[2].empty()) {
            while (!q[currLab].empty()) {
                int u = q[currLab].front();
                q[currLab].pop();
                for (int v : adjList[u]) {
                    inDegree2[v]--;
                    if (inDegree2[v] == 0) {
                        if (labss[v] == 1) q[1].push(v);
                        else q[2].push(v);
                    }
                }
            }

            // go to next lab
            if (currLab == 1) currLab = 2;
            else currLab = 1;
            ans2++;
        }

        cout << min(ans1, ans2) - 1 << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



