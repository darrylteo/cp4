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
    for (int cases = 1; cases <= T; ++cases) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;
        sort(A.begin(), A.end());
        for (int i = 0; i < N; i += 2) {
            if (A[i] != A[i + 1]) {
                cout << "Case #" << cases << ": " << A[i] << '\n';
                break;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}