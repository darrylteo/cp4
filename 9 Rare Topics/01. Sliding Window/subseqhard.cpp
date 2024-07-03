#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// classic question. subarray sum equals to k

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<ll, int> mp; // sum -> count
        ll sum = 0;
        int ans = 0;
        mp[0] = 1;
        while (n--) {
            int x;
            cin >> x;
            sum += x;
            if (mp.find(sum - 47) != mp.end()) {
                ans += mp[sum - 47];
            }
            mp[sum]++;
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}