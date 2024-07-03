#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M, N && M) {
        int ans = 0;
        unordered_set<int> jack;
        while (N--) {
            int x;
            cin >> x;
            jack.insert(x);
        }
        while (M--) {
            int x;
            cin >> x;
            if (jack.find(x) != jack.end()) {
                ans++;
            }
        }
        cout << ans << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
