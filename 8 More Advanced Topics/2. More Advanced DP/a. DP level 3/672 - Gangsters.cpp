#include <bits/stdc++.h>

using namespace std;

struct gangster {
    int t, p, s;

    bool operator<(const gangster &rhs) const {
        return t < rhs.t;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        if (t > 0) cout << endl;
        int N, K, T;
        cin >> N >> K >> T;
        vector<gangster> gangsters(N+1);
        for (int i = 1; i <= N; i++) cin >> gangsters[i].t;
        for (int i = 1; i <= N; i++) cin >> gangsters[i].p;
        for (int i = 1; i <= N; i++) cin >> gangsters[i].s;
        sort(gangsters.begin(), gangsters.end());
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1)); // gangster id, openness. record max profit
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) { // gangster id
            for (int j = 0; j <= K; j++) { // openness
                for (int k = 0; k <= K; k++) { // check all openness
                    // amt of time passed since last gangster visited must be enough to reach k from j
                    if (dp[i - 1][k] != -1 && abs(k - j) <= gangsters[i].t - gangsters[i - 1].t) {
                        // if the openness == gangster i stoutness, add profit
                        // plus 0 when you can reach state but not used by current gangster
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == gangsters[i].s ? gangsters[i].p : 0));
                    }
                }
            }
        }
        cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}


