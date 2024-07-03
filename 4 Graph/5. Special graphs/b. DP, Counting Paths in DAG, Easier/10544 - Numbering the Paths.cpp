#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;

// idea: use adj2 to find how many paths starting from [i]
// if we skip [i], we skipped pathCnt[i] paths so far

// btw the normal adj would give us no. of paths ending at [i]
// e.g. if push [0] can count how many paths from [0] to [i] as per textbook description pg 251

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<set<int>> adj(n), adj2(n); // adj2 is transposed, to find how many paths starting from [i]
        vi inDegree(n, 0);
        string s;
        for (int i = 0; i < m; i++) {
            cin >> s;
            adj[s[0] - 'A'].insert(s[1] - 'A');
            if(adj2[s[1] - 'A'].insert(s[0] - 'A').second) { // sadkek debugging here i realised my ans were diff with repeated. using set made me oblivious to repeated edges... waste 1h oh noes from simple qn to time waster qn
                inDegree[s[0] - 'A']++;
            }
        }

        queue<int> q;
        vll pathCnt(n, 0);
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                pathCnt[i] = 1;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: adj2[u]) {
                pathCnt[v] += pathCnt[u];
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        int Q;
        cin >> Q;
        while (Q--) {
            cin >> s;
            ll ans = 1;
            for (int i = 0; i < s.size() - 1; ++i) {
                int u = s[i] - 'A';
                int t = s[i + 1] - 'A';
                for (int v: adj[u]) {
                    if (v == t) break;
                    ans += pathCnt[v];
                }
            }
            cout << s << ": " << ans << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
