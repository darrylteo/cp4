#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
// micro = 0, goo = 1
// micro left, goo left, micro consec left, goo consec left
ll memo[35][35][35][35];
int D, G;

inline ll dp(int micro, int goo, int microConsec, int gooConsec) {
    if (micro < 0 || goo < 0 || microConsec < 0 && micro > 0 || gooConsec < 0 && goo > 0) return 0; // no way
    if (micro == 0 && goo == 0) return 1; // 1 way
    if (goo == 0) return 0; // no way since finished other guy 1st
    ll &ans = memo[micro][goo][microConsec][gooConsec];
    if (ans != -1) return ans;
    if (micro == D && goo == D) {
        ans = dp(micro - 1, goo, G, gooConsec - 1);
    } else {
        ans = dp(micro - 1, goo, G, gooConsec - 1) +
              dp(micro, goo - 1, microConsec - 1, G);
    }
    return ans;
}

// not too hard but there's so many random conditions like away for how many days, EXCEPT when project completed
// must choose first day project to match project that completed 1st etc. we put micro as 1st, then 2x ans.
// weirchamp clue to use 6 parameters... probably could even abstract out the consec
// but it's good learning point. at 1st included days/which project 1st,
// which led to TLE and for 6 param, and ギリセーフ of 1.0s runtime for include days only
// current formulation 0.03s. guess somehow abstract out the consec would be 0s.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 1;
    memset(memo, -1, sizeof(memo));
    while (cin >> D >> G, D != -1) {
        ll ans = 2 * dp(D, D, G, G);
        if (D == 0) ans = 0;
        cout << "Case " << cases++ << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}



