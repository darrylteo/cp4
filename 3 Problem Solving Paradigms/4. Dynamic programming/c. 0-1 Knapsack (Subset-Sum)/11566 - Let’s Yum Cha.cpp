#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 210; // up to 100 dimsum types (and can order twice of each type)
const int MAX_W = 1200; // up to $100 and 11 ppl (incl. self)
const int MAX_K = 25; // order up to 2 dimsum per person

// V is taste value, remW is remaining money left, remK is remaining cnt of dimsum
// maximize total taste value is same as maximize average taste value. later just print ans / (N + 1)
int N, x, T, K, W[MAX_N], V[MAX_N], memo[MAX_N][MAX_W][MAX_K];

int dp(int id, int remW, int remK) {
    if ((id == K) || (remW == 0) || (remK == 0)) return 0;        // two base cases
    int &ans = memo[id][remW][remK];
    if (ans != -1) return ans;                     // computed before
    if (W[id] > remW) return ans = dp(id + 1, remW, remK); // no choice, skip
    return ans = max(dp(id + 1, remW, remK), V[id] + dp(id + 1, remW - W[id], remK - 1));  // or take
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> x >> T >> K, N || x || T || K) {
        memset(W, 0, sizeof W);
        memset(V, 0, sizeof V);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < K; ++i) {
            cin >> W[i]; // price
            W[K + i] = W[i]; // double dimsum
            int totalTaste = 0;
            for (int j = 0; j < N + 1; ++j) {
                int tmp;
                cin >> tmp;
                totalTaste += tmp;
            }
            V[i] = totalTaste;
            V[K + i] = totalTaste; // double dimsum
        }
        // double dimsum since u can order 2 of same type
        K *= 2;
        // money to spend on dimsum
        // amt of money after svc charge - cost of teas
        // eps for errors
        int money = x * (N + 1) / 1.1 + 1e-6 - (N + 1) * T;
        if (money < 0) {
            cout << "0.00" << endl;
            continue;
        }
        cout << fixed << setprecision(2) << round((double) dp(0, money, 2 * (N + 1)) / (N + 1) * 100) / 100 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
