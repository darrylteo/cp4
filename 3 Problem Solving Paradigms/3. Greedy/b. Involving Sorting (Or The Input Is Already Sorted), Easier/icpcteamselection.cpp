#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<int> scores(N * 3);
        for (int &x: scores) cin >> x;
        sort(scores.begin(), scores.end());
        // ignore bottom 1/3 as they will not be median
        int ans = 0;
        // alternate ppl from top 2/3 will be median
        for (int j = N; j < N * 3; j += 2) {
            ans += scores[j];
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

