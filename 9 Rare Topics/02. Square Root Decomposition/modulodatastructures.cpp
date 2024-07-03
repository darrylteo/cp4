#include <bits/stdc++.h>

using namespace std;

// just follow book
// note that we use 1 indexing
// just implementing what book says is easy but to think of it on the spot is >.<

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    int sqrt_n = ceil(sqrt(N));
    vector<int> v(N + 1);
    vector<vector<int>> bucket(sqrt_n + 1, vector<int>(sqrt_n + 1)); // divisor, remainder
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int A, B, C;
            cin >> A >> B >> C;
            if (B <= sqrt_n) {
                bucket[B][A] += C;
            } else {
                int j = A;
                while (j <= N) {
                    v[j] += C;
                    j += B;
                }
            }
        } else {
            int D;
            cin >> D;
            int ans = v[D];
            for (int i = 1; i <= sqrt_n; i++) {
                ans += bucket[i][D % i];
            }
            cout << ans << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}