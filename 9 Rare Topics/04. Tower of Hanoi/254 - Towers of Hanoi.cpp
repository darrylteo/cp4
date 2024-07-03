#include <bits/stdc++.h>

using namespace std;

// trying out the algorithm given in the problem statement, you will find out that for even n, the dest peg is C
// and for odd n, the dest peg is B
// wish we didn't have to deal with __int128 -_-

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    string ss;
    while (cin >> n >> ss, n) {
        __int128 m = 0, one = 1;
        for (char c : ss) m = m * 10 + (c - '0');

        vector<int> ans(3);
        int s = 0, i = 1, t = 2; // source, intermediate, target pegs
        if (n % 2) swap(i, t);
        // the largest one would have gone to target peg if we made 2^(n-1) moves
        // only care about the largest disc at each iteration
        for (int l = n - 1; l >= 0; --l) {
            if (m >= (one << l)) {
                ans[t]++;
                m -= one << l;
                swap(s, i);
            } else {
                ans[s]++; // largest disc didn't move since too little moves
                swap(i, t); // same reason as the (n%2) thingy
            }
        }
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}