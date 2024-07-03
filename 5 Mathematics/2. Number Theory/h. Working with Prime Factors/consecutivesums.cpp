#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// sum AP = n/2[2a + (n – 1)]
// 2*sum = n * (2a + n - 1)
// a = (2*sum/n - n + 1)/2
// test all factors

void printAns(ull a, ull n, ull sum) {
    cout << sum << " = " << a;
    for (ull i = 1; i < n; i++) {
        cout << " + " << a + i;
    }
    cout << '\n';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ull sum;
        cin >> sum;
        int found = 0;
        sum *= 2;
        for (ull n = 2; n * n <= sum; n++) {
            if (sum % n == 0) {
                ull a = sum / n - n + 1;
                if (a % 2 == 0) {
                    printAns(a / 2, n, sum / 2);
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            cout << "IMPOSSIBLE\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}