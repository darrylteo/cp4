#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int S, C;
vector<vector<int>> concerts, travel, memo;

inline int dp(int store, int concert) {
    if (concert == C - 1) return concerts[store][concert];
    int &ans = memo[store][concert];
    if (ans != -1) return ans;
    // pick a store to perform next concert
    for (int i = 0; i < S; ++i) {
        ans = max(ans, dp(i, concert + 1) - travel[store][i] + concerts[store][concert]);
    }
    return ans;
}

// phew finally easy dp. 142/149 users solved this :S

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> S >> C;
        concerts.assign(S, vector<int>(C));
        memo.assign(S, vector<int>(C, -1));
        travel.assign(S, vector<int>(S));
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < C; j++) {
                cin >> concerts[i][j];
            }
        }
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                cin >> travel[i][j];
            }
        }
        int best = 0;
        for (int i = 0; i < S; ++i) {
            best = max(best, dp(i, 0));
        }
        cout << best << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

