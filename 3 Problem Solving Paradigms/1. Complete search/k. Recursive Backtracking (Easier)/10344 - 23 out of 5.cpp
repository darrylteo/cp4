#include <bits/stdc++.h>

using namespace std;

// testing to see if permutation works

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e;
    end:
    while (cin >> a >> b >> c >> d >> e) {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) break;
        vector<int> v = {a, b, c, d, e};
        sort(v.begin(), v.end());
        do {
            int ans = 0;
            for (int i1 = 0; i1 < 3; i1++) {
                for (int i2 = 0; i2 < 3; i2++) {
                    for (int i3 = 0; i3 < 3; i3++) {
                        for (int i4 = 0; i4 < 3; i4++) {
                            if (i1 == 0) ans = v[0] + v[1];
                            else if (i1 == 1) ans = v[0] - v[1];
                            else if (i1 == 2) ans = v[0] * v[1];

                            if (i2 == 0) ans += v[2];
                            else if (i2 == 1) ans -= v[2];
                            else if (i2 == 2) ans *= v[2];

                            if (i3 == 0) ans += v[3];
                            else if (i3 == 1) ans -= v[3];
                            else if (i3 == 2) ans *= v[3];

                            if (i4 == 0) ans += v[4];
                            else if (i4 == 1) ans -= v[4];
                            else if (i4 == 2) ans *= v[4];

                            if (ans == 23) {
                                cout << "Possible" << endl;
                                goto end;
                            }
                        }
                    }
                }
            }
        } while (next_permutation(v.begin(), v.end()));
        cout << "Impossible" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

