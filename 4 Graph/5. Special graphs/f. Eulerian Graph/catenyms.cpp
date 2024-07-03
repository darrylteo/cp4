#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vector<pair<string, int>> AL[26];
int N = 26, m;

inline void hierholzer(int start) {
    stack<pair<string,int>> st;
    st.emplace("z", start); // dummy node
    vi idx(N, 0);
    vector<string> ans;
    while (!st.empty()) {
        auto &[s, u] = st.top();
        if (idx[u] < AL[u].size()) {
            st.emplace(AL[u][idx[u]]);
            idx[u]++;
        } else {
            ans.push_back(s);
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() != m + 1) { // graph is disconnected. see second sample input
        cout << "***" << endl;
        return;
    }
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ".";
    }
    cout << endl;
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_4_Graph/Special_Graphs/kattis_catenyms.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> m;
        for (auto &i: AL) i.clear();
        vi inDeg(N, 0), outDeg(N, 0);
        string s;
        int u, v;
        for (int i = 0; i < m; i++) {
            cin >> s;
            u = s[0] - 'a';
            v = s[s.size() - 1] - 'a';
            AL[u].emplace_back(s, v);
            inDeg[v]++;
            outDeg[u]++;
        }
        for (auto &i: AL) sort(i.begin(), i.end());

        // check path or cycle or none
        int startCycleNode = -1, startPathNode = -1;
        int extraOut = 0, extraIn = 0, same = 0;
        for (int i = 0; i < N; i++) {
            if (inDeg[i] == outDeg[i]) {
                same++;
                // need in deg > 0 since its a cycle
                if (inDeg[i] > 0 && startCycleNode == -1) startCycleNode = i; // indeg=outdeg=0 means letter not used
            } else if (inDeg[i] == outDeg[i] + 1) {
                extraIn++;
            } else if (inDeg[i] + 1 == outDeg[i]) {
                extraOut++;
                startPathNode = i;
            }
        }

        if (same == N) {
            hierholzer(startCycleNode);
        } else if (same == N - 2 && extraIn == 1 && extraOut == 1) {
            hierholzer(startPathNode);
        } else {
            cout << "***" << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


