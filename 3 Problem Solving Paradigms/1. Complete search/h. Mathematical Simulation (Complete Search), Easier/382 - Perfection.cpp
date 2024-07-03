#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "PERFECTION OUTPUT" << endl;
    int n;
    while (cin >> n, n) {
        int sum = 0;
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                sum += i;
            }
        }
        cout << setw(5) << n << "  ";
        if (sum == n) {
            cout << "PERFECT" << endl;
        } else if (sum < n) {
            cout << "DEFICIENT" << endl;
        } else {
            cout << "ABUNDANT" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}