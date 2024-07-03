#include <bits/stdc++.h>

using namespace std;

struct pt {
    int x, y;
};
int N;
vector<pt> pts;
vector<int> pens, cumPens;

// although i'm bad at bottom up dp, this seems more natural

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N, N) {
        pts.resize(N + 2);
        pens.resize(N + 2);
        pts[0] = {0, 0};
        pens[0] = 0;
        for (int i = 1; i <= N; i++) cin >> pts[i].x >> pts[i].y >> pens[i];
        pts[N + 1] = {100, 100};
        pens[N + 1] = 0;
        vector<vector<double>> dist(N + 2, vector<double>(N + 2));
        for (int i = 0; i < N + 2; i++) {
            for (int j = i + 1; j < N + 2; j++) {
                double dis = sqrt(pow(pts[i].x - pts[j].x, 2) + pow(pts[i].y - pts[j].y, 2));
                dist[i][j] = dist[j][i] = dis;
            }
        }
        cumPens.resize(N + 2);
        cumPens[0] = pens[0];
        for (int i = 1; i < N + 2; i++) cumPens[i] = cumPens[i - 1] + pens[i];
        vector<double> dp(N + 2);
        for (int i = 0; i < N + 2; i++) dp[i] = 1e9;
        dp[0] = 0;
        for (int i = 0; i < N + 2; i++) {
            for (int j = i + 1; j < N + 2; j++) {
                int penl = cumPens[j - 1] - cumPens[i];
                dp[j] = min(dp[j], dp[i] + dist[i][j] + penl + 1);
            }
        }
        cout << fixed << setprecision(3) << dp[N + 1] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

