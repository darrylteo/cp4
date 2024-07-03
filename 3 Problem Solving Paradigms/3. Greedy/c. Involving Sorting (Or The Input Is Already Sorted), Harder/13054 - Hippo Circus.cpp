#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Case " << i + 1 << ": ";
        int N, H, Ta, Td;
        cin >> N >> H >> Ta >> Td;
        vector<int> heights(N);
        for (int j = 0; j < N; ++j) {
            cin >> heights[j];
        }
        // in case walking by themselves are faster
        if (2 * Ta <= Td) {
            cout << N * Ta << endl;
            continue;
        }

        sort(heights.begin(), heights.end());
        ll ans = 0;
        int l = 0, r = N - 1;
        while (l < r) {
            if (heights[l] + heights[r] < H) { // if can pair, pair
                ans += Td;
                l++;
                r--;
            } else { // if cannot, current r elephant go by itself, continue find smaller elephant
                ans += Ta;
                r--;
            }
        }
        if (l == r) { // if there is one elephant left, it go by itself
            ans += Ta;
        }
        cout << ans << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

