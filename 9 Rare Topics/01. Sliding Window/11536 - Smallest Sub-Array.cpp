#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> A(N);
        A[0] = 1;
        A[1] = 2;
        A[2] = 3;
        for (int i = 3; i < N; ++i) {
            A[i] = (A[i - 1] + A[i - 2] + A[i - 3]) % M + 1;
        }
        int start = 0, end = 0, ans = INT_MAX;
        vector<int> freq(K + 1);
        freq[0] = 1; // ignore 0
        int cnt = 0;
        while (end < N) {
            while (cnt != K && end < N) {
                if (A[end] <= K) {
                    freq[A[end]]++;
                    if (freq[A[end]] == 1) cnt++;
                }
                end++;
            }
            while (cnt == K && start < N) {
                ans = min(ans, end - start);
                if (A[start] <= K) {
                    freq[A[start]]--;
                    if (freq[A[start]] == 0) cnt--;
                }
                start++;
            }
        }
        cout << "Case " << cases << ": ";
        if (ans == INT_MAX)cout << "sequence nai" << endl;
        else cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}