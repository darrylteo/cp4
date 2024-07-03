#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case " << cases << ": ";
        int N;
        cin >> N;
        vi ans;
        // let N-X be on top and sqrt(N) be at the bottom
        for (int i = 1; i <= sqrt(N); ++i) {
            int top = N - i * i;
            int bot = i;
            if (top % bot == 0) {
                ans.push_back(top);
            }
        }
        if (ans.back() == 0) {
            ans.pop_back();
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if (i < ans.size() - 1) {
                cout << " ";
            }
        }
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

