#include <bits/stdc++.h>

using namespace std;

// tested on https://www.udebug.com/UVa/11517, it seems like u can't take more than 1 of each coin
// aka knapsack problem (got the value in 5 mins, counting coins in 45min -_-)
const int MAX_N = 110;
const int MAX_W = 10010;

int N, V[MAX_N];
pair<int, int> memo[MAX_N][MAX_W];

// memo contains best answer for the state (id, remW), and the number of coins taken
// return -extrapaid if poid too much, return -1e7 if never paid finish
pair<int, int> dp(int id, int remV) {
    if (remV <= 0) return make_pair(-remV, 0);          // good, paid finish. returns -extrapaid, later count coins backwards
    if ((id == N)) return make_pair(1e7,1e7);       // bad, never paid finish
    pair<int, int> &ans = memo[id][remV];
    if (ans.first != -1) return ans;
    pair<int, int> exclude = dp(id + 1, remV);
    pair<int, int> include = dp(id + 1, remV - V[id]);
    include.second++; // count coins here
    ans = min(include, exclude);
    return ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int price;
        cin >> price >> N;
        for (int i = 0; i < N; ++i) cin >> V[i];
        memset(memo, -1, sizeof memo); // reset memo
        pair<int, int> ans = dp(0, price);
        cout << price + ans.first << " " << ans.second << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
