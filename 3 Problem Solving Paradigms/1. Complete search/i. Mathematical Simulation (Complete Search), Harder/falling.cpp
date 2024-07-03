#include <bits/stdc++.h>

using namespace std;

// check until the difference is greater than D. if reach here then is impossible
// e.g. first sample input is 88, 45^2-44^2 = 89. if haven't found ans, break and impossible
// obviously n2 must be greater than sqrt(D) too.
// for sample 1 we must check 9 to 45 for n2 and 0 to 44 for n1... how is that sqrt(D)?
// need long long since 100000^2 - 99999^2 = 199999. the squares are greater than 2^32

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D;
    cin >> D;
    long long n1, n2;
    for (n2 = sqrt(D);; ++n2) {
        if (n2 * n2 - (n2-1) * (n2-1) > D) break;
        n1 = sqrt(n2 * n2 - D);
        if (n1 * n1 == n2 * n2 - D) {
            cout << n1 << " " << n2 << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}