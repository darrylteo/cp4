#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> cum;

bool bad(int i, int m) {
    return cum[i + m - 1] - cum[i - 1] > S || cum[i + 2 * m - 1] - cum[i + m - 1] > S;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> S;
    cum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cum[i];
        cum[i] += cum[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        int l = 0, r = (N - i + 1) / 2;
        while (l < r) {
            int m = (l + r) / 2;
            // if use bad() here will WA since there may be better solution than bad(),
            // but for sure no better solution than this
            // recall BSTA property is that if bad(i, m) is true, then bad(i, m + 1) is also true
            if (cum[i + 2 * m - 1] - cum[i - 1] > 2 * S) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        while (bad(i, l)) {
            l--;
        }
        cout << 2 * l << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

