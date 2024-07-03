#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        vector<int> v(x);
        for (int &i: v) cin >> i;
        sort(v.begin(), v.end(), greater<int>());
        long long ans = 0;
        for (int i = 2; i < x; i += 3) {
            ans += v[i];
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

