#include <bits/stdc++.h>

using namespace std;

// just follow book

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, S;
    while (cin >> N >> S) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        int sum = 0, start = 0, end = 0, min_len = N + 1;
        while (end < N) {
            while (sum < S && end < N) {
                sum += arr[end++];
            }

            while (sum >= S && start < N) {
                min_len = min(min_len, end - start);
                sum -= arr[start++];
            }
        }

        cout << (min_len == N + 1 ? 0 : min_len) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}