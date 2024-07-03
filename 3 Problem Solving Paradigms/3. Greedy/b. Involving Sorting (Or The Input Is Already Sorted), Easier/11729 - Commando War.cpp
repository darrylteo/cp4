#include <bits/stdc++.h>

using namespace std;

struct soldier {
    int brief, job;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n, n) {
        cout << "Case " << cases++ << ": ";
        vector<soldier> soldiers(n);
        for (int i = 0; i < n; ++i) {
            cin >> soldiers[i].brief >> soldiers[i].job;
        }
        sort(soldiers.begin(), soldiers.end(), [](const soldier &a, const soldier &b) {
            return a.job > b.job;
        });
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += soldiers[i].brief;
            ans = max(ans, sum + soldiers[i].job);
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

