#include <bits/stdc++.h>

using namespace std;

// test all possible subsets of the array (of course break when found)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cout << "Case #" << cases << ":\n";
        int x;
        vector<int> v(20);
        cin >> x;
        for (int i = 0; i < 20; ++i) cin >> v[i];
        map<int, int> mp; // sum, mask
        int found = 0;
        for (int mask = 1; mask < (1 << 20); ++mask) {
            int sum = 0;
            for (int i = 0; i < 20; ++i) {
                if (mask & (1 << i)) {
                    sum += v[i];
                }
            }
            if (mp.find(sum) != mp.end()) {
                int mask2 = mp[sum];
                for (int i = 0; i < 20; ++i) {
                    if (mask & (1 << i)) {
                        cout << v[i] << " ";
                    }
                }
                cout << endl;
                for (int i = 0; i < 20; ++i) {
                    if (mask2 & (1 << i)) {
                        cout << v[i] << " ";
                    }
                }
                cout << endl;
                found = 1;
                break;
            }
            mp[sum] = mask;
        }
        if (!found) cout << "Impossible" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}