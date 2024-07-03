#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vi AL[10005];
int n, m;

inline void hierholzer(int start) {
    stack<int> st;
    st.emplace(start);
    vi idx(n, 0);
    vi ans;
    while (!st.empty()) {
        int u = st.top();
        if (idx[u] < AL[u].size()) {
            st.emplace(AL[u][idx[u]]);
            idx[u]++;
        } else {
            ans.push_back(u);
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() != m + 1) {
        cout << "Impossible" << endl;
        return;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << " ";
    }
    cout << endl;
}

// owo freebie qn same as previous qn catenyms

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> n >> m, n) {
        for (auto &i: AL) i.clear();
        vi inDeg(n, 0), outDeg(n, 0);
        string s;
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            AL[u].push_back(v);
            outDeg[u]++;
            inDeg[v]++;
        }

        // check path or cycle or none
        int startCycleNode = -1, startPathNode = -1;
        int extraOut = 0, extraIn = 0, same = 0;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == outDeg[i]) {
                same++;
                // need in deg > 0 since its a cycle
                if (inDeg[i] > 0 && startCycleNode == -1) startCycleNode = i; // only assign once
            } else if (inDeg[i] == outDeg[i] + 1) {
                extraIn++;
            } else if (inDeg[i] + 1 == outDeg[i]) {
                extraOut++;
                startPathNode = i;
            }
        }

        if (same == n) {
            hierholzer(startCycleNode);
        } else if (same == n - 2 && extraIn == 1 && extraOut == 1) {
            hierholzer(startPathNode);
        } else {
            cout << "Impossible\n";
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


