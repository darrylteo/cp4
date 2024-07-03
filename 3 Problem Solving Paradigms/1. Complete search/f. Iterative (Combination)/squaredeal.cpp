#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> v;
    v.reserve(3);
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    do {
        // check if permutation is valid given all rotations
        for (int i = 0; i < 1 << 3; i++) {
            bitset<3> bs(i);
            int a1, a2, b1, b2, c1, c2;
            if (bs[0]) {
                a1 = v[0].first;
                a2 = v[0].second;
            } else {
                a1 = v[0].second;
                a2 = v[0].first;
            }
            if (bs[1]) {
                b1 = v[1].first;
                b2 = v[1].second;
            } else {
                b1 = v[1].second;
                b2 = v[1].first;
            }
            if (bs[2]) {
                c1 = v[2].first;
                c2 = v[2].second;
            } else {
                c1 = v[2].second;
                c2 = v[2].first;
            }

                // condition (a)
            if (a1 == b1 && b1 == c1 && a2 + b2 + c2 == a1) {
                cout << "YES\n";
                return 0;
            }

            // condition (b)
            if (a1 + b1 == c1 && a2 + c2 == c1) {
                cout << "YES\n";
                return 0;
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "NO\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}