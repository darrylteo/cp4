#include <bits/stdc++.h>

using namespace std;

// sum of AP (d == 1): n/2 * (2a + (n-1)) = an + n(n-1)/2 = N
// a = (N - n(n-1)/2) / n if INT ok
// for upper bound sqrt(2N) to 1 is because when a == 1, n + n^2 <= 2N implies approx. n <= sqrt(2N) limit

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N, N != -1) {
        int n = sqrt(2 * N), flag = 0;
        while (n >= 1) {
            int a = (N - n * (n - 1) / 2) / n;
            if (a == (N - n * (n - 1) / 2.0) / n) {
                cout << N << " = " << a << " + ... + " << a + n - 1 << '\n';
                flag = 1;
                break;
            }
            --n;
        }
        if (!flag) cout << N << " = " << N << " + ... + " << N << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

