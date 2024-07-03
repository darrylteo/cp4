#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    set<pair<ll, ll>> s;
    ll N, Q;
    cin >> N >> Q;
    ll ans = 0;
    for (int q = 0; q < Q; ++q) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll l, r;
            cin >> l >> r;
            if (s.find({l, r}) == s.end()) { // a new segment to consider
                // add the new segment
                s.insert({l, r});
                ans += r - l + 1;

                // merge old segments
                // check if need extend left by checking the segment just before l
                auto it = s.lower_bound({l, 0});
                if (it != s.begin()) {
                    --it;
                    if (it->second >= l) {
                        ans -= it->second - it->first + 1; // remove the old segment
                        l = it->first;
                        r = max(r, it->second);
                        s.erase(it);
                    }
                }
                // check if need extend right
                // here extension is done by checking the segment just after r
                // if r exceeds the l of the next segment, then merge them
                // i see it as the r ate up the left tail of next segment,
                // then see if it continues on and eat up right tail (overlap) or part way of new segment and stop there.
                it = s.lower_bound({l, 0});
                while (it != s.end() && it->first <= r) {
                    ans -= it->second - it->first + 1; // remove the old segment
                    r = max(r, it->second);
                    s.erase(it++);
                }
                // add the new segment
                s.insert({l, r});
                ans += r - l + 1;
            }
        } else cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
