#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// just check each number appears <= n times

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        int nsq = n * n;
        int cnt[101] = {};
        for (int i = 0; i < nsq; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        bool ok = true;
        for (int i = 0; i <= 100; ++i) {
            if (cnt[i] > n) {
                ok = false;
                break;
            }
        }
        cout << "Case " << cases << ": " << (ok ? "yes" : "no") << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

