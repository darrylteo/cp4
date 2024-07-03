#include <bits/stdc++.h>

using namespace std;

int n, memo[1 << 20]; // for each subset of students, save the minimum number of students needed to teach them all
vector<int> v;

int dp(int maskChoice, int maskCovered) {
    if (maskCovered == (1 << n) - 1) return 0;
    if (memo[maskChoice] != -1) return memo[maskChoice];

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (!(maskChoice & (1 << i))) {
            int newMaskChoice = maskChoice | (1 << i);
            int newMaskCovered = maskCovered | v[i];
            ans = min(ans, 1 + dp(newMaskChoice, newMaskCovered));
        }
    }

    return memo[maskChoice] = ans;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        v.assign(n, 0);
        for (int i = 0; i < n; i++) {
            int nn;
            cin >> nn;
            v[i] |= 1 << i;
            for (int j = 0; j < nn; j++) {
                int x;
                cin >> x;
                x--;
                v[i] |= 1 << x;
            }
        }
        memset(memo, -1, sizeof(memo));
        cout << dp(0,0) << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}