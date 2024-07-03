#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & (-S))

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        int X, n;
        cin >> X >> n;
        int l[n];
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
        }
        int i;
        for (i = 0; i < (1<<n); ++i) { // for each subset, O(2^n)
            int sum = 0;
            int mask = i; // this is now O(k)
            while (mask) { // k is the # of on bits
                int two_pow_j = LSOne(mask); // least significant bit
                int j = __builtin_ctz(two_pow_j); // 2^j = two_pow_j, get j
                sum += l[j];
                mask -= two_pow_j;
            }
            if (sum == X) {
                cout << "YES" << endl;
                break; // the answer is found
            }
        }
        if (i == (1<<n)) {
            cout << "NO" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
