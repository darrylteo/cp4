#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

const int MAX_n = 17;
int dist[MAX_n][MAX_n], memo[MAX_n][1<<(MAX_n-1)]; // Karel + max 10 beepers

int dp(int u, int mask) {                        // mask = free coordinates
    if (mask == 0) return dist[u][0];              // close the loop
    int &ans = memo[u][mask];
    if (ans != -1) return ans;                     // computed before
    ans = 2000000000;
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v)+1;          // offset v by +1. // ctz = count trailing zeros
        ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

vector<int> path;
void getPath(int u, int mask) {                    // backtracking routine
    if (mask == 0) return;                         // close the loop
    double opt = dp(u, mask);
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v)+1;          // offset v by +1. // ctz = count trailing zeros
        if (fabs(opt - (dist[u][v] + dp(v, mask ^ two_pow_v))) < 1e-9) { // if same, same state
            path.push_back(v);
            getPath(v, mask ^ two_pow_v); // recurse on this state
            return;
        }
        m -= two_pow_v;
    }
}

// hmmm so far my tsp solutions are ranked quite badly (very slow)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        for (int i = 0; i < MAX_n; ++i)
            for (int j = 0; j < MAX_n; ++j)
                dist[i][j] = 1e7;
        memset(memo, -1, sizeof memo);

        int N, M;
        cin >> N >> M;

        vector<char> nodes;
        vector<int> nodesId;
        for (int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            nodes.push_back(c);
            nodesId.push_back(i);
        }

        sort(nodes.begin() + 1, nodes.end() - 1); // cheap way to find lexigraphically smallest

        for (int i = 0; i < M; ++i) {
            char start, end;
            cin >> start >> end;
            bool found = false;
            for (int j = 0; j < N; ++j) {
                if (nodes[j] == start && !found) {
                    for (int k = 0; k < N; ++k) {
                        if (nodes[k] == end) {
                            dist[j][k] = 1;
                            dist[k][j] = 1;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        dist[N-1][0]=0; // so target node is last
        path.clear();
        getPath(0, (1<<(N-1))-1);
        if (dp(0, (1<<(N-1))-1) >= 1e7 || nodes[nodes.size()-1] != nodes[path[path.size()-1]]) {
            cout << "Case " << cases << ": " << "impossible" << endl;
            continue;
        }

        cout << "Case " << cases << ": " << nodes[0];
        for (int i = 0; i < path.size(); ++i) {
            cout << nodes[path[i]];
        }
        cout << endl;



    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}