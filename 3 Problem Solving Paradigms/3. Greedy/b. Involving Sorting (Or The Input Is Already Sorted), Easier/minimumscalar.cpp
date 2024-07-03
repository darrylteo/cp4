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
    for (int cases = 1; cases <= T; cases++) {
        int N;
        cin >> N;
        vector<long long> v1(N), v2(N);
        for (long long &i: v1) cin >> i;
        for (long long &i: v2) cin >> i;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += v1[i] * v2[i];
        }
        cout << "Case #" << cases << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

