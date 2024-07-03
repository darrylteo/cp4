#include <bits/stdc++.h>

using namespace std;

// a = missing length (total missing is 2*a*a), b = thickness, S = total
// S = 6 * b * b + 7 * b * a (has to be similar to sample diagram)
// check for each b if a = (S - 6 * b * b) / (7 * b) is an integer. stop when negative

#define big 100000007

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long S;
    while (cin >> S, S) {
        int flag = 0;
        int max_b = sqrt(S / 6);
        for (long long b = 1; b <= max_b; ++b) {
            b = b % big;
            long long a = (S - 6 * b * b) / (7 * b);
            if (a > 0 && a == (S - 6 * b * b) / (7.0 * b)) {
                cout << "Possible Missing Soldiers = " << 2 * a % big * a % big << "\n";
                flag = 1;
            }
        }

        if (!flag) cout << "No Solution Possible\n";
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

