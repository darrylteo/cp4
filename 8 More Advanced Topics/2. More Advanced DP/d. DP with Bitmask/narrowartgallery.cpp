#include <bits/stdc++.h>

using namespace std;
// prev row is either (in binary) 00, 01, 10 where 1 means it was closed
int memo[205][3][205]; // row, prev row, k left
vector<vector<int>> rooms;
int N;

int dp(int r, int prev, int k_left){
    if (r == N) {
        if (k_left == 0) return 0;
        return -1e9;
    }
    int &ans = memo[r][prev][k_left];
    if (ans != -1) return ans;
    ans = dp(r + 1, 0, k_left) + rooms[r][0] + rooms[r][1]; // open both rooms
    if (k_left > 0) {
        int blockRight = dp(r + 1, 1, k_left - 1) + rooms[r][0]; // block right room. get value of left.
        int blockLeft = dp(r + 1, 2, k_left - 1) + rooms[r][1]; // block left room
        if (prev == 0) {
            ans = max(ans, blockRight);
            ans = max(ans, blockLeft);
        } else if (prev == 1) {
            ans = max(ans, blockRight);
        } else {
            ans = max(ans, blockLeft);
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    cin >> N >> k;
    rooms.resize(N, vector<int>(2));
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < N; i++) cin >> rooms[i][0] >> rooms[i][1];
    cout << dp(0, 0, k) << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
